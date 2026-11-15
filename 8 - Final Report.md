# Selection Sort Without Loops, Recursion or goto

**Name:** Aouine Nasim   **Course:** ASD3   **Teacher:** L. Lamiche   **Date:** 24/10/2026

---

### Navigation: Click any blue link to open the file

## 1. The Problem
The teacher gave us this challenge:
- Write **Selection Sort** in C++ / C / Pseudo-code.
- **Rules:** No loops (`for`, `while`, `do-while`), no recursion, no `goto`.
- **Size:** Unknown size $N$ at runtime.
- **Hint:** The algorithm contains **booleans**.
- Teacher said it was given in a PhD algorithms exam.

See details in [1 - The Problem.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/1%20-%20The%20Problem.md).

---

## 2. Research Steps & Program Evolution

Documented in [2 - Research map.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/2%20-%20Research%20map.md) and [Daily Notes](file:///home/wsm/Desktop/Selection%20Sort%20Project/3%20-%20Daily%20Notes).

### The Attempts:
1. **[version1.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version1.cpp)** `[FAILED]`:
   Tried mutual function calls (A calls B, B calls A). It failed because calling in a cycle is indirect recursion.
2. **[version2.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version2.cpp)** `[WORKS]`:
   Discovered the C++ constructor trick: creating `new T[n]` runs the constructor $N$ times without any loop.
3. **[version3.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version3.cpp)** `[WORKS]`:
   Tested nested repetition: an outer constructor creating inner constructors ($n - i - 1$ times).
4. **[version4.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version4.cpp)** `[WORKS]`:
   First working Selection Sort using constructors and boolean comparison `arr[j] < arr[min_index]`. Had a memory leak because of missing `delete[]`.
5. **[version5.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version5.cpp)** `[WORKS]`:
   Fixed the memory leak with `delete[] new Inner[...]`, cleaned up `swap(x, y)`, and added AI review comments.

---

## 3. The Final Solution: Selection Sort

👉 **Program:** **[final_version.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/final_version.cpp)** `[FINAL]`

### Why this is the real solution:
- It is **true Selection Sort**: it finds the minimum in the unsorted section and swaps it.
- **Zero loops:** `selectionSort()` has 0 loops, and `printArray()` uses a `Printer` constructor so even printing has 0 loops.
- **Memory safe:** all allocated arrays are cleaned up with `delete[]`.
- **Clean and simple:** basic C++ arrays, no complicated `std::vector` or advanced templates.

### Compilation & Execution:
```bash
g++ -std=c++17 -Wall -Wextra "4 - The Program/final_version.cpp" -o final_version
./final_version
```

### Test Results (All Passed):
See full log in [5 - Tests.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/5%20-%20Tests.md).

| # | Test Input | Expected | Output | Status |
|---|---|---|---|---|
| 1 | `5 2 9 1 7` | `1 2 5 7 9` | `1 2 5 7 9` | **PASS** |
| 2 | `42` (single item) | `42` | `42` | **PASS** |
| 3 | `3 3 1 2` (duplicates) | `1 2 3 3` | `1 2 3 3` | **PASS** |
| 4 | `9 8 7 6 5 4` (reverse) | `4 5 6 7 8 9` | `4 5 6 7 8 9` | **PASS** |
| 5 | `3 -1 -5 0` (negative) | `-5 -1 0 3` | `-5 -1 0 3` | **PASS** |
| 6 | `[]` (empty array) | `[Empty array]` | `[Empty array]` | **PASS** |

---

## 4. Extra Research: The Boolean Matrix & PhD Question

During research, I looked at floor tiles (*carrelage*) and wondered if we could compare all pairs at once on an $N \times N$ grid.
This led to discovering the **Boolean Comparison Matrix** (often taught in PhD parallel PRAM courses):
- Prototype: **[version6_matrix_concept.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version6_matrix_concept.cpp)**
- Clean version: **[version7_matrix_clean.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version7_matrix_clean.cpp)**
- Complete matrix sort: **[final_matrix_sort.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/final_matrix_sort.cpp)**
- Theoretical Pseudo-code: **[The PhD Solution - Pseudo-code.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/The%20PhD%20Solution%20-%20Pseudo-code.md)**

### Important Difference (Why my Selection Sort is better for this task):
- The Boolean Matrix is scientifically called **Rank Sort** (or Enumeration Sort), because it calculates ranks without swapping.
- The teacher specifically requested **Selection Sort**.
- Since in C++ both methods use the constructor trick to avoid loops on a single CPU, **[final_version.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/final_version.cpp)** is the direct, honest answer to the teacher's exact question.

---

## 5. Honest Discussion & Conclusion

1. **Did we remove loops completely?**
   In our code: yes, there are no `for`, `while`, `do`, `recursion`, or `goto`.
   In reality: the C++ runtime handles the repetition inside the constructor array allocation.
2. **What does the boolean do?**
   In Selection Sort (`final_version.cpp`), the boolean condition `arr[j] < arr[min_index]` decides which item is the smallest to swap.
3. **C Alternative:**
   In pure C (where constructors do not exist), we proved it can be done with `<setjmp.h>` (`setjmp`/`longjmp`) in **[alternative_c_setjmp.c](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/alternative_c_setjmp.c)**.
