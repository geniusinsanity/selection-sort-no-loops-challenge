# The PhD Solution: Boolean Comparison Matrix (Pseudo-code)

This document explains the pure theoretical solution to the challenge, as given in PhD algorithm exams.

---

## 1. Mathematical Concept

Let $A$ be an array of $N$ elements: $A = [A[0], A[1], \dots, A[N-1]]$.

We define an $N \times N$ **Boolean Matrix** $B$, where each cell $B[i][j]$ is a boolean value (`true` or `false`):

$$B[i][j] = (A[i] > A[j]) \lor (A[i] == A[j] \land i > j)$$

### What does each row mean?
Row $i$ compares element $A[i]$ with all other elements in the array:
- If $A[i]$ is bigger than $k$ elements, exactly $k$ booleans in row $i$ will be `true`.
- Therefore, the final sorted position (Rank) of $A[i]$ is:

$$\text{Rank}(i) = \sum_{j=0}^{N-1} B[i][j]$$

- Finally, element $A[i]$ is placed directly at:

$$\text{Sorted}[\text{Rank}(i)] = A[i]$$

---

## 2. General Pseudo-code (No Loops, No Recursion)

In advanced algorithmics (Parallel PRAM model), the algorithm is written in straight mathematical / parallel notation without any iterative `for` or `while` loops:

```pascal
Algorithm BooleanMatrixSort(A, N)
Input:  Array A of size N
Output: Sorted array Sorted of size N

Step 1: Compute Boolean Matrix in Parallel
    For all pairs (i, j) where 0 <= i, j < N do in parallel:
        B[i][j] <- (A[i] > A[j]) OR (A[i] == A[j] AND i > j)

Step 2: Compute Ranks in Parallel
    For each i where 0 <= i < N do in parallel:
        Rank[i] <- Sum(B[i][0..N-1])

Step 3: Route Elements
    For each i where 0 <= i < N do in parallel:
        Sorted[Rank[i]] <- A[i]

Return Sorted
```

---

## 3. Why This Answers the Professor's Riddle

1. **"The algorithm contains booleans":**
   The entire data structure is literally an $N \times N$ matrix of booleans (`true` / `false`).
2. **"No loops, no recursion, no goto":**
   In theoretical computer science, all $N^2$ comparisons are independent and evaluated concurrently.
3. **"Works for any size N":**
   The mathematical formula holds true for any arbitrary $N$.
4. **General Pseudo-code vs C++:**
   - In **Pseudo-code**, this algorithm is **general** and does not require language hacks.
   - In **C++**, because a CPU executes sequentially, we implemented this exact matrix using object constructors (`delete[] new MatrixCell[n]`) to invoke the comparisons without writing `for` loops.
