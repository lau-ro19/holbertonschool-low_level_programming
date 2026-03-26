# Crash Report — `crash_example.c`

**File:** `crash_example.c`  
**Observed signal:** `SIGSEGV` (Segmentation Fault), exit code 139  
**Crash confirmed:** Yes — reproduced deterministically on every run.

-----

## 1. Observed Behavior

```
crash_example: deterministic NULL dereference (segmentation fault)
  requesting n=0
Segmentation fault (core dumped)
```

The program prints both `printf` lines that precede the call to
`allocate_numbers`, then terminates with signal 11 (`SIGSEGV`) before
reaching either of the two `printf` calls that follow it. Exit code 139
(128 + 11) confirms a signal-terminated process.

-----

## 2. Root Cause Analysis

### 2.1 Causal chain — step by step

**Step 1 — `n` is initialised to 0.**

```c
int n = 0;
```

`n` lives on `main`’s stack frame at `rbp-0xc`. The disassembly confirms
the compiler emits `movl $0x0, -0xc(%rbp)` — zero is the value that will
be passed to the function.

**Step 2 — `allocate_numbers(0)` is called.**

```c
nums = allocate_numbers(n);   /* n == 0 */
```

The integer argument 0 is loaded into `%edi` and the function is called.

**Step 3 — The guard condition is hit immediately and `NULL` is returned.**

```c
if (n <= 0)
    return NULL;
```

The disassembly at offset `0x11c7` shows `cmpl $0x0, -0x14(%rbp)` followed
by `jg 11d4` — the jump is *not* taken when `n == 0`, so execution falls
through to `mov $0x0, %eax` and then `jmp 1233` (the epilogue). No call to
`malloc` is ever made. `NULL` (`0x0`) is returned in `%rax`.

**Step 4 — The return value is stored into `nums` without any NULL check.**

```c
nums = allocate_numbers(n);   /* nums is now NULL */
nums[0] = 42;                 /* ← crash here */
```

Back in `main`, the disassembly at `0x1282` stores `%rax` (which is `0x0`)
into `nums` at `rbp-0x8`. There is no conditional branch between the `call`
and the next instruction. The very next instruction at `0x1286`–`0x128a` is:

```asm
mov    -0x8(%rbp), %rax   ; load nums (= 0x0) into rax
movl   $0x2a, (%rax)      ; write 42 to address 0x0  ← SIGSEGV
```

**Step 5 — The CPU attempts to write to virtual address `0x0`.**

Virtual address `0x0` is not mapped in the process’s address space. On
Linux, the first page (address 0 through 4095) is deliberately left
unmapped so that NULL dereferences trap immediately. The MMU raises a page
fault, the kernel converts it to `SIGSEGV`, and the process is terminated.

### 2.2 Category of undefined behavior

This is a **NULL pointer dereference** — specifically a **write through a
NULL pointer**. It belongs to the broader class *“use of an invalid
pointer value”* defined in ISO C11 §6.5.3.2 ¶4: dereferencing a pointer
that does not point to an object produces undefined behavior.

It is **not** a use-after-free, a heap buffer overflow, or a stack
overflow. The pointer was never valid to begin with; it was never assigned
a heap address.

### 2.3 Memory region involved

|Variable    |Location                   |Value at crash                |
|------------|---------------------------|------------------------------|
|`n`         |stack (`rbp-0xc` in `main`)|`0`                           |
|`nums`      |stack (`rbp-0x8` in `main`)|`0x0` (NULL)                  |
|write target|virtual address `0x0`      |unmapped — no physical backing|

Neither the heap nor a valid stack object is accessed. The fault is a
write to the **zero page** — the canonical unmapped sentinel address.

-----

## 3. Why the Memory Access Is Invalid

`malloc` was *never called*. The guard `if (n <= 0) return NULL` is
correct defensive code, but it transfers the obligation to check the
return value to the *caller*. `main` does not honour that obligation — it
unconditionally dereferences `nums` regardless of what `allocate_numbers`
returned.

Dereferencing NULL is invalid for two independent reasons:

1. **C language rule:** A null pointer does not point to any object. The
   standard forbids dereferencing it (UB, C11 §6.5.3.2 ¶4).
1. **OS enforcement:** Virtual address `0x0` falls inside the unmapped
   null-page region that every Linux process reserves precisely to catch
   this class of bug at runtime. The page-fault trap is a safety net, not
   the cause — the undefined behavior exists whether or not the hardware
   catches it.

-----

## 4. Critical Evaluation of AI-Provided Explanations

When this code was submitted to an AI assistant for analysis, the
following explanation was offered:

> *“The segmentation fault occurs because `malloc` returns `NULL` when it
> cannot allocate memory, and the program then dereferences that NULL
> pointer. This can happen when the system is under memory pressure or the
> heap is exhausted.”*

### What is correct

The second half — “the program then dereferences that NULL pointer” — is
accurate. The mechanism (NULL dereference → SIGSEGV) is correctly
identified.

### What is wrong

The stated *cause* of the NULL return is **incorrect**. The AI attributed
it to heap exhaustion or memory pressure. That is false here.

`malloc` is **never called at all**. The NULL is returned by the explicit
`if (n <= 0) return NULL` guard *before* the code even reaches the
`malloc` call. This is visible in the disassembly: at offset `0x11cd` the
function loads `0` into `%eax` and jumps directly to the function
epilogue, skipping the `malloc` call at `0x11e0` entirely.

The AI’s explanation implies the bug is non-deterministic (dependent on
available memory). In reality it is **fully deterministic** — it fires on
every run regardless of available memory, because it is caused by
unconditionally passing `n = 0` to a function that explicitly rejects
non-positive values.

This distinction matters for diagnosis: the AI’s explanation would lead an
engineer to add retry logic or increase available memory, which would not
fix anything. The real fix is to check the return value of
`allocate_numbers` before using it.

-----

## 5. Suggested Fix *(labeled as optional / not required by task)*

```c
nums = allocate_numbers(n);

if (nums == NULL)           /* ← add this guard */
{
    fprintf(stderr, "allocation failed or n=%d is invalid\n", n);
    return 1;
}

nums[0] = 42;
```

Alternatively, pass a valid positive value for `n`:

```c
int n = 5;   /* or any n > 0 */
```

Either change eliminates the NULL dereference. The guard approach is
preferable in production code because it handles both the `n <= 0` case
and a genuine `malloc` failure.

-----

## 6. Summary Table

|Item                    |Detail                                                                                                                              |
|------------------------|------------------------------------------------------------------------------------------------------------------------------------|
|**Crash type**          |NULL pointer dereference (write)                                                                                                    |
|**Faulting instruction**|`movl $0x2a, (%rax)` — `rax = 0x0`                                                                                                  |
|**Source line**         |`nums[0] = 42;`                                                                                                                     |
|**Root cause**          |`allocate_numbers(0)` returns NULL due to `n <= 0` guard; caller never checks return value                                          |
|**Memory region**       |Virtual address `0x0` — unmapped null page (neither heap nor stack)                                                                 |
|**UB category**         |Dereferencing a null pointer (C11 §6.5.3.2 ¶4)                                                                                      |
|**Determinism**         |100% deterministic — independent of system memory                                                                                   |
|**AI explanation error**|AI attributed NULL to heap exhaustion; actual cause is an early `return NULL` guard triggered by `n == 0` before `malloc` is reached|