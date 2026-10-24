# Selection Sort Without Loops, Recursion or goto: The Complete Journey

**Name:** Aouine Nasim   **Course:** ASD3   **Teacher:** L. Lamiche   **Date:** 24/10/2026

---

### Navigation: Click any blue link to view its file

## 1. The Problem & Challenge
The assignment given by the teacher:
- Write **Selection Sort** in C++ / C / Pseudo-code.
- **Constraints:** No loops (`for`, `while`, `do-while`), no recursion, no `goto`.
- **Runtime size $N$:** The algorithm must work for an unknown size $N$.
- **Hint:** The algorithm contains **booleans**.
- **Context:** The teacher mentioned this was from a PhD algorithms exam.

Full details are documented in [1 - The Problem.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/1%20-%20The%20Problem.md).

---

## 2. The Research Journey & Evolution of Code

Documented across [2 - Research map.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/2%20-%20Research%20map.md) and the [Daily Notes](file:///home/wsm/Desktop/Selection%20Sort%20Project/3%20-%20Daily%20Notes).

### Phase 1: Sequential Simulation in C++
- **[version1.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version1.cpp)** `[state:failed]`
  Tried mutual function calls (Function A calls B, B calls A). Failed because mutual calls form a cycle on the call stack, which is indirect recursion.
- **[version2.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version2.cpp)** `[state:works]`
  Discovered the C++ constructor trick: `new T[n]` forces the runtime to call the constructor $N$ times.
- **[version3.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version3.cpp)** `[state:works]`
  Simulated nested loops by having an `Outer` constructor instantiate `Inner` constructors with variable size ($n - i - 1$).
- **[version4.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version4.cpp)** `[state:works]`
  First working Selection Sort using constructors and boolean `(arr[j] < arr[min_index])`. Weakness: heap memory leak and imperfect `swap`.
- **[version5.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version5.cpp)** `[state:works]`
  Fixed memory leaks using `delete[] new Inner[...]`, cleaned `swap(x, y)`, and added AI review comments.

### Phase 2: The Breakthrough — The "Floor Tiles" Revelation & The Boolean Comparison Matrix
While walking down the university hallway, looking at the square floor tiles (*le carrelage*) forming an $N \times N$ grid, a new perspective emerged:
> Why search for the minimum step-by-step?
> What if we compare all elements at once on an $N \times N$ grid of booleans?
> The number of `true` values in row $i$ is the exact final rank of element $A[i]$!

Research confirmed this is formally known as **Parallel Enumeration / Rank Sort using a Boolean Comparison Matrix**—a classic PhD exam problem in PRAM / parallel models!

- **[version6_matrix_concept.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version6_matrix_concept.cpp)** `[state:works]`
  Prototype of Boolean Comparison Matrix sort. Worked for distinct elements.
- **[version7_matrix_clean.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/version7_matrix_clean.cpp)** `[state:works]`
  Handled duplicates using tie-breaker condition `(arr[i] == arr[j]) && (i > j)`. Handled edge cases ($N \le 1$). Simple arrays, no `std::vector`.
- **[final_matrix_sort.cpp](file:///home/wsm/Desktop/Selection%20Sort%20Project/4%20-%20The%20Program/final_matrix_sort.cpp)** `[state:final]`
  The ultimate master program: zero loops in sorting AND zero loops in printing (`MatrixPrinter`), zero memory leaks, passed all test cases.

---

## 3. The Theoretical Solution: General Pseudo-code

The complete theoretical explanation and pseudo-code are detailed in:  
👉 **[The PhD Solution - Pseudo-code.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/The%20PhD%20Solution%20-%20Pseudo-code.md)**

### Mathematical Formula:
$$B[i][j] = (A[i] > A[j]) \lor (A[i] == A[j] \land i > j)$$
$$\text{Rank}(i) = \sum_{j=0}^{N-1} B[i][j]$$
$$\text{Sorted}[\text{Rank}(i)] = A[i]$$

### General Pseudo-code:
```pascal
Algorithm BooleanMatrixSort(A, N)
1. For all (i, j) in parallel: B[i][j] <- (A[i] > A[j]) OR (A[i] == A[j] AND i > j)
2. For each i in parallel:     Rank[i] <- Sum(B[i][0..N-1])
3. For each i in parallel:     Sorted[Rank[i]] <- A[i]
Return Sorted
```

---

## 4. Tests and Verification

Program: `final_matrix_sort.cpp`  
Compiler: `g++ -std=c++17 -Wall -Wextra`

Detailed logs in [5 - Tests.md](file:///home/wsm/Desktop/Selection%20Sort%20Project/5%20-%20Tests.md).

| # | Input | Expected Output | Actual Output | Status |
|---|---|---|---|---|
| 1 | `5 2 9 1 7` | `1 2 5 7 9` | `1 2 5 7 9` | **PASS** |
| 2 | `42` (single element) | `42` | `42` | **PASS** |
| 3 | `3 3 1 2 3` (duplicates) | `1 2 3 3 3` | `1 2 3 3 3` | **PASS** |
| 4 | `9 8 7 6 5 4` (reversed) | `4 5 6 7 8 9` | `4 5 6 7 8 9` | **PASS** |
| 5 | `3 -1 -5 0 2` (negatives) | `-5 -1 0 2 3` | `-5 -1 0 2 3` | **PASS** |
| 6 | `[]` (empty array) | `[Empty array]` | `[Empty array]` | **PASS** |

---

## 5. Honest Discussion & Conclusions

1. **Why Pseudo-code is the General Solution:**
   In **Pseudo-code**, the algorithm is general and needs no programming tricks, because mathematical set operations evaluate all comparisons simultaneously.
2. **The Role of C++ Constructors:**
   In practical sequential C++, the CPU needs a mechanism to trigger comparisons. Using object constructors (`new MatrixCell[n]`) bridges the gap, fulfilling the constraint of no `for`, `while`, `do`, `recursion`, or `goto`.
3. **The Teacher's Hint:**
   The hint **"contains booleans"** is the core key: every entry in the $N \times N$ matrix is a boolean comparison that directly dictates the element's position.
