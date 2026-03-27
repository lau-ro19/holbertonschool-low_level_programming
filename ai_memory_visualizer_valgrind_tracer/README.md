# 0x12. C - Singly Linked Lists: Memory & Debugging Analysis

## 📋 Overview
This project focuses on the implementation and manipulation of singly linked lists in C. Beyond the code, this repository includes a series of analytical documents (`.md`) designed to demonstrate a deep understanding of memory management, pointer aliasing, and the use of debugging tools like Valgrind.

---

## 📂 Memory & Logic Analysis Files

### 1. [Valgrind Analysis](./valgrind_analysis.md)
* **Objective**: Interpreting memory reports to eliminate leaks and invalid accesses.
* **Key Insights**: 
    * Identifying "definitely lost" blocks (missing `free()`).
    * Differentiating between **Memory Leaks** (forgetting to free) and **Memory Errors** (Invalid Read/Write).
    * Connecting Valgrind stack traces to specific lines in the source code.

### 2. [Memory Maps: Stack vs Heap](./memory_maps.md)
* **Objective**: Visualizing data organization during program execution.
* **Key Insights**:
    * **Stack**: Management of local variables and function pointers (e.g., `list_t *head`).
    * **Heap**: Dynamic storage of nodes and strings duplicated via `malloc` and `strdup`.
    * **Lifetimes**: Explaining why heap data survives function returns while stack data is reclaimed.

### 3. [Crash Report (Segmentation Fault)](./crash_report.md)
* **Objective**: Diagnosing the root cause of crashes as deterministic events.
* **Key Insights**:
    * Analysis of NULL pointer dereferencing.
    * Identifying "Use-After-Free" scenarios where a pointer refers to an invalid memory address.
    * Explaining the hardware/OS response to illegal memory access.

---

## 🛠️ Critical Use of AI & Peer Review Preparation
This project was developed with AI as a collaborative partner. In accordance with the evaluation criteria:
* **AI Limitation Identified**: Initial AI suggestions for `free_list` sometimes proposed freeing a node before accessing its `next` pointer—a classic **Use-After-Free** bug. 
* **Correction**: I manually implemented a temporary pointer to store the `next` address before freeing the current node, ensuring the list link is never lost during destruction.
* **Validation**: All logic was cross-verified using `betty` for style and `valgrind` for memory integrity.

---

## 🚀 Compilation & Usage
To compile the project using the school's flags:
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o alx_lists