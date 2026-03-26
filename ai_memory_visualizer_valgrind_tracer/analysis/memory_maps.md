Memory Maps Analysis
Programs analyzed

stack_example.c — recursion and stack frames
heap_example.c — heap allocations and deliberate leak
aliasing_example.c — pointer aliasing and use-after-free
crash_example.c — deterministic NULL dereference


Program 1 — stack_example.c
Source overview
main calls walk_stack(0, 3), which recurses up to depth 3.
At each level, dump_frame is called twice (on entry and exit).
Key execution points
Step 0 — main stack frame
STACK
┌─────────────────────────────────┐
│ main()                          │
│   [no local variables used]     │
│   return address → OS           │
└─────────────────────────────────┘
Step 1 — walk_stack(0, 3) called
STACK (grows downward)
┌─────────────────────────────────┐  HIGH ADDRESS
│ main()                          │
├─────────────────────────────────┤
│ walk_stack(depth=0, max=3)      │
│   marker = 0   (&marker = 0x7fff...A0)  │
└─────────────────────────────────┘
Inside walk_stack, dump_frame("enter", 0) is called:
STACK
┌─────────────────────────────────┐
│ main()                          │
├─────────────────────────────────┤
│ walk_stack(depth=0, max=3)      │
│   marker = 0                    │
├─────────────────────────────────┤
│ dump_frame(label="enter", depth=0) │
│   local_int  = 100  (&local_int = 0x7fff...80) │
│   local_buf[16] = "A\0..."  (&local_buf = 0x7fff...70) │
│   p_local = &local_int  (value = 0x7fff...80) │
└─────────────────────────────────┘  LOW ADDRESS
Variable lifetimes in dump_frame:

local_int, local_buf, p_local are born when dump_frame is entered
They are destroyed when dump_frame returns
p_local is a pointer to local_int — both live on the same frame

Step 2 — Full recursion (depth 0 → 3)
STACK at maximum depth (depth=3)
┌──────────────────────────────────┐  HIGH ADDRESS
│ main()                           │
├──────────────────────────────────┤
│ walk_stack(depth=0)  marker=0    │
├──────────────────────────────────┤
│ walk_stack(depth=1)  marker=10   │
├──────────────────────────────────┤
│ walk_stack(depth=2)  marker=20   │
├──────────────────────────────────┤
│ walk_stack(depth=3)  marker=30   │
│   (no further recursion here)    │
└──────────────────────────────────┘  LOW ADDRESS
Each walk_stack frame has its own independent marker variable.
&marker addresses decrease as depth increases (stack grows downward).
Step 3 — Unwinding (exit path)
As each walk_stack returns, its frame is popped:
Unwinding order:
walk_stack(3) → dump_frame("exit",3) → return
walk_stack(2) → dump_frame("exit",2) → return
walk_stack(1) → dump_frame("exit",1) → return
walk_stack(0) → dump_frame("exit",0) → return
main() → return 0
After each return, the corresponding marker variable no longer exists.
The address it occupied may be reused by the next function call.
HEAP
No heap allocations in this program.
AI correction note — Program 1
An AI tool initially described p_local as "a pointer stored on the heap".
This is incorrect. p_local is declared as int *p_local = &local_int inside
dump_frame. Both p_local and local_int are local variables — they live
entirely on the stack within the dump_frame frame. No malloc is called
anywhere in this program.

Program 2 — heap_example.c
Source overview
Creates two Person structs on the heap. Bob is correctly freed.
Alice's name field is never freed — deliberate memory leak.
Key execution points
Step 1 — person_new("Alice", 30) called
Inside person_new:
STACK
┌──────────────────────────────────┐
│ main()   alice=NULL  bob=NULL    │
├──────────────────────────────────┤
│ person_new(name="Alice", age=30) │
│   p    = (Person*) malloc result │
│   len  = 5  (strlen "Alice")     │
│   i    = 0..4 (loop counter)     │
└──────────────────────────────────┘

HEAP
┌──────────────────────────────────┐
│ Person struct (sizeof=16 bytes)  │  ← p points here (e.g. 0x5555...10)
│   name → 0x5555...30            │
│   age  = 30                      │
├──────────────────────────────────┤
│ char[6] "Alice\0"                │  ← p->name points here (0x5555...30)
└──────────────────────────────────┘
Step 2 — person_new("Bob", 41) called
HEAP after both allocations
┌──────────────────────────────────┐
│ Person "Alice"  (0x5555...10)    │
│   name → 0x5555...30            │
│   age  = 30                      │
├──────────────────────────────────┤
│ char[6] "Alice\0" (0x5555...30) │
├──────────────────────────────────┤
│ Person "Bob"    (0x5555...50)    │
│   name → 0x5555...60            │
│   age  = 41                      │
├──────────────────────────────────┤
│ char[4] "Bob\0"  (0x5555...60)  │
└──────────────────────────────────┘

STACK (main)
│ alice = 0x5555...10              │
│ bob   = 0x5555...50              │
Step 3 — free(bob->name) then free(bob)
HEAP after bob freed
┌──────────────────────────────────┐
│ Person "Alice"  (0x5555...10)    │  ← still allocated
│   name → 0x5555...30            │
│   age  = 30                      │
├──────────────────────────────────┤
│ char[6] "Alice\0" (0x5555...30) │  ← still allocated
├──────────────────────────────────┤
│ [freed] (0x5555...50)            │  ← bob struct returned to OS
├──────────────────────────────────┤
│ [freed] (0x5555...60)            │  ← bob->name returned to OS
└──────────────────────────────────┘
bob (stack variable) still holds address 0x5555...50 but it is now
a dangling pointer. It must not be dereferenced.
Step 4 — person_free_partial(alice) called
cstatic void person_free_partial(Person *p)
{
    if (!p)
        return;
    free(p);   /* frees the Person struct only */
               /* p->name is NOT freed → memory leak */
}
HEAP after person_free_partial(alice)
┌──────────────────────────────────┐
│ [freed] (0x5555...10)            │  ← alice struct freed
├──────────────────────────────────┤
│ char[6] "Alice\0" (0x5555...30) │  ← LEAKED — never freed
└──────────────────────────────────┘
Valgrind summary (expected)
definitely lost: 6 bytes in 1 blocks   ← alice->name
AI correction note — Program 2
An AI tool stated: "both Alice and Bob are leaked because person_free_partial
does not free the name field."
This is partially incorrect. Bob is fully and correctly freed:
free(bob->name) is called explicitly in main, followed by free(bob).
Only Alice's name field is leaked. The Person struct for alice is freed
by person_free_partial, but the char *name it pointed to is not.
The leak is exactly 6 bytes ("Alice\0"), not the full struct.

Program 3 — aliasing_example.c
Source overview
make_numbers(5) allocates an int array. b = a creates an alias.
After free(a), both a and b become dangling pointers.
The program then reads and writes through b — use-after-free.
Key execution points
Step 1 — make_numbers(5) returns
HEAP
┌──────────────────────────────────────────────┐
│ int[5]  (0x5555...20)                        │
│  [0]=0  [1]=11  [2]=22  [3]=33  [4]=44       │
└──────────────────────────────────────────────┘

STACK (main)
│ a = 0x5555...20   │
│ b = NULL          │
│ n = 5             │
Step 2 — b = a (aliasing)
STACK (main)
│ a = 0x5555...20   │──┐
│ b = 0x5555...20   │──┘──► same heap block
│ n = 5             │

HEAP
┌──────────────────────────────────────────────┐
│ int[5]  (0x5555...20)                        │
│  [0]=0  [1]=11  [2]=22  [3]=33  [4]=44       │
└──────────────────────────────────────────────┘
Both a and b point to the exact same memory block.
a[2] and b[2] both read value 22.
Step 3 — free(a) called
HEAP
┌──────────────────────────────────────────────┐
│ [freed block] (0x5555...20)                  │
│  content undefined — may be overwritten      │
└──────────────────────────────────────────────┘

STACK (main)
│ a = 0x5555...20   │  ← DANGLING (freed, not NULL)
│ b = 0x5555...20   │  ← DANGLING (freed, not NULL)
After free(a), both a and b are dangling pointers.
The memory block no longer belongs to the program.
Step 4 — b[2] read (use-after-free)
b[2] accesses address: 0x5555...20 + 2*sizeof(int) = 0x5555...28
This address was freed. Reading it is undefined behavior.
The value returned may appear correct (22) or may be garbage,
depending on whether the allocator has reused or zeroed the block.
Valgrind reports: Invalid read of size 4.
Step 5 — b[3] = 1234 write (use-after-free write)
b[3] writes to address: 0x5555...20 + 3*sizeof(int) = 0x5555...2C
Writing to freed memory corrupts the heap allocator's internal
data structures. This is undefined behavior and can cause
crashes or security vulnerabilities later.
Valgrind reports: Invalid write of size 4.
Pointer aliasing summary
VariablePoints toStatus after free(a)a0x5555...20danglingb0x5555...20dangling
Both variables alias the same block. Freeing through one pointer
invalidates all aliases — neither can be safely used afterwards.
AI correction note — Program 3
An AI tool described the state after free(a) as:
"a is now NULL and b still points to the valid array."
This is entirely incorrect on both counts.
In C, free() does NOT set the pointer to NULL. After free(a),
a still holds the address 0x5555...20 — it is a dangling pointer,
not NULL. Additionally, b is equally dangling because it holds the
same address. The heap block is no longer valid for either pointer.
Setting pointers to NULL after free is a programmer responsibility,
not something the C runtime does automatically.

Program 4 — crash_example.c
Source overview
main calls allocate_numbers(0). Because n <= 0, the function
returns NULL. The program then dereferences nums[0] = 42 on a
NULL pointer — deterministic segmentation fault.
Key execution points
Step 1 — allocate_numbers(0) called
STACK
┌─────────────────────────────────────┐
│ main()  nums=NULL  n=0              │
├─────────────────────────────────────┤
│ allocate_numbers(n=0)               │
│   arr = NULL                        │
│   i   = 0                           │
│   → n <= 0 branch taken            │
│   → return NULL                     │
└─────────────────────────────────────┘

HEAP: nothing allocated
Step 2 — Back in main, nums = NULL
STACK (main)
│ nums = NULL  (0x0000...0000)  │
│ n    = 0                      │
allocate_numbers returned NULL because n == 0.
No heap allocation was made.
Step 3 — nums[0] = 42 → CRASH
nums[0]  translates to:  *(nums + 0)  =  *(NULL + 0)  =  *(0x0)
Address 0x0 is never mapped in a process's virtual memory.
The CPU raises a segmentation fault signal (SIGSEGV).
The OS kills the process immediately.
MEMORY MAP at crash point
┌──────────────────────────────────┐
│ Stack: valid                     │
│   nums = 0x0000000000000000      │
├──────────────────────────────────┤
│ Heap: empty (nothing allocated)  │
├──────────────────────────────────┤
│ Address 0x0: NOT MAPPED → CRASH  │
└──────────────────────────────────┘
Variable lifetimes
VariableBorn atDies atLocationnmain() entrymain() returnstacknumsmain() entrySIGSEGV crashstackarrallocate_numbers()return NULLstack
AI correction note — Program 4
An AI tool stated: "the crash occurs because malloc failed and
returned NULL due to insufficient memory."
This is incorrect. malloc is never called in this execution path.
The function allocate_numbers explicitly checks if (n <= 0) return NULL
before reaching malloc. Since n = 0, the early return is taken and
the heap is never touched. The NULL dereference is caused entirely by
the missing return value check in main after calling allocate_numbers.
The crash is deterministic and reproducible regardless of available memory.

Global memory summary
ProgramStack framesHeap allocsHeap freesLeaksUBstack_example4 recursive00nonenoneheap_example2 functions4 blocks3 blocks6 bytesnonealiasing_example2 functions1 block1 blocknoneuse-after-free r/wcrash_example2 functions00noneNULL deref (SIGSEGV)

AI corrections summary
ProgramAI claimWhy it was wrongstack_examplep_local stored on the heapp_local is a local variable — lives on the stack inside dump_frameheap_exampleboth Alice and Bob are leakedBob is fully freed in main; only alice->name (6 bytes) is leakedaliasing_exampleafter free(a), a is NULL and b is validfree() never sets pointers to NULL; both a and b are danglingcrash_examplecrash caused by malloc failuremalloc is never reached; early return NULL before n<=0 check