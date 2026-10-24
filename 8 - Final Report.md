# Selection Sort Without Loops, Recursion or goto

**Name:** Aouine Nasim   **Course:** ASD3   **Teacher:** L. Lamiche   **Date:** 24/10/2026

---

### Navigation: Click any blue link to view its file

## 1. The Problem
A detailed description of the challenge is in [The Problem](file:///home/wsm/Desktop/Selection%20Sort%20Project/1%20-%20The%20Problem.md).
The task is to implement **Selection Sort** with:
- **No loops** (`for`, `while`, `do-while`)
- **No recursion** (direct or indirect)
- **No `goto`**
- Variable array size $N$ known only at runtime.
- **Hint:** The algorithm relies on **booleans**.

## 2. The Language
We primarily use **C++**, with an additional investigation into **C** and theoretical algorithmic models.

## 3. How I Searched & Road Map
Documented in the [Research Map](file:///home/wsm/Desktop/Selection%20Sort%20Project/2%20-%20Research%20map.md) and [Mistakes & Lessons](file:///home/wsm/Desktop/Selection%20Sort%20Project/6%20-%20Mistakes%20and%20Lessons.md).

---

## 4. Progressive Programs & Evolutionary Path

**1. [version1.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version1.cpp)** `[state:failed]` `[rules:recursion]`
- **What I did:** Repetition using mutual function calls (Function A calls Function B, which calls Function A).
- **Why it failed:** Even without a function directly calling itself, any cycle in the call stack constitutes indirect recursion. Forbidden!

**2. [version2.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version2.cpp)** `[state:works]` `[rules:ok]`
- **What I did:** Proved the concept of loop-free repetition in C++ using object constructors (`new loop2[n]`).
- **What I learned:** Creating an array of $N$ objects forces the C++ runtime to invoke the default constructor $N$ times.

**3. [version3.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version3.cpp)** `[state:works]` `[rules:ok]`
- **What I did:** Simulated nested loops by having the outer constructor dynamically create an array of inner constructors with variable sizes ($n - i - 1$).
- **What I learned:** Dynamic sizing works smoothly inside constructors without loops.

**4. [version4.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version4.cpp)** `[state:works]` `[rules:ok]`
- **What I did:** First full working Selection Sort combining constructors with the boolean condition `(arr[j] < arr[min_index])`.
- **Identified weaknesses:** Had a memory leak (missing `delete[]`) and still used a `for` loop in `main()` for printing.

**5. [version5.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version5.cpp)** `[state:works]` `[rules:ok]`
- **What I did:** Fixed the memory leak using `delete[] new Inner[...]`, cleaned up `swap(x, y)` references, and handled edge cases ($N \le 1$).

**6. [final_version.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/final_version.cpp)** `[state:final]` `[rules:ok]`
- **What I did:** Added a constructor-based `Printer` struct, eliminating 100% of loops across the entire file (both sorting and printing).
- **Result:** Fully memory-safe, supports all edge cases, zero compiler warnings.

**7. Alternative C Solution: [alternative_c_setjmp.c](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/alternative_c_setjmp.c)** `[state:works]` `[rules:ok]`
- **What I did:** Implemented the algorithm in pure C using `<setjmp.h>` (`setjmp` and `longjmp`) with booleans.
- **Why it matters:** If the teacher meant pure C (where constructors do not exist), `longjmp` is the standard library mechanism for non-local control flow jumps without `goto`.

---

## 5. Tests

**Program:** `4 - The Program/final_version.cpp`  
**Compiler:** `g++ -std=c++17 -Wall -Wextra`

Detailed test log available in [5 - Tests.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/5%20-%20Tests.md).

| # | Input | Expected | Output | Result |
|---|---|---|---|---|
| 1 | `5 2 9 1 7` | `1 2 5 7 9` | `1 2 5 7 9` | **PASS** |
| 2 | `42` (single element) | `42` | `42` | **PASS** |
| 3 | `3 3 1 2` (repeated values) | `1 2 3 3` | `1 2 3 3` | **PASS** |
| 4 | `9 8 7 6 5 4` (reverse order) | `4 5 6 7 8 9` | `4 5 6 7 8 9` | **PASS** |
| 5 | `3 -1 -5 0` (negative numbers) | `-5 -1 0 3` | `-5 -1 0 3` | **PASS** |
| 6 | `[]` (empty array) | `[Empty array]` | `[Empty array]` | **PASS** |

---

## 6. Limits and Honest Discussion (What is really happening?)

1. **Did we truly eliminate repetition?**
   No. Computationally, sorting an unsorted dynamic array of $N$ items requires $\Omega(N \log N)$ or $O(N^2)$ comparisons. We did not eliminate iteration; we delegated the loop to the **C++ runtime / memory allocator**, which executes a loop behind the scenes when initializing array elements.
2. **What might the PhD question have intended?**
   - **Possibility A (C++ Language Trick):** The Constructor lifecycle trick (our primary solution).
   - **Possibility B (C Low-Level Jumping):** Using `setjmp`/`longjmp` with boolean guards.
   - **Possibility C (Theoretical Pseudo-code / Boolean Comparison Matrix):** In algorithmic theory, sorting can be represented without sequential loops as an $N \times N$ Boolean Matrix:
     $$B[i][j] = (A[i] > A[j])$$
     The sum of booleans in row $i$ gives the exact final index of element $A[i]$.

---

## 7. Sources
Full details in [7 - Sources and AI Questions.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/7%20-%20Sources%20and%20AI%20Questions.md).
- GeeksforGeeks & Microsoft Learn: Array constructor repetition mechanisms.
- Cppreference: Standard object lifetime rules.
- AI Assistant: Pair programming, bug detection, memory leak resolution, and code review.
