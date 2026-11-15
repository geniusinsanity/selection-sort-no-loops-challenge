# 6 - Mistakes and Lessons

Never delete a wrong idea. Write what went wrong and what it taught me.

| # | Date | Wrong idea | Why it failed | Lesson |
|---|---|---|---|---|
| 1 | 18 Oct 2026 | Build a loop from booleans only | Boolean logic gives one answer, it cannot repeat | Repetition needs time, memory or self-reference |
| 2 | 18 Oct 2026 | Use a sorting network for the whole problem | The size must be fixed when writing the code | Writing steps out by hand cannot handle a size typed at runtime |
| 3 | 18 Oct 2026 | Search "sort array C++" | Results use std::sort or loops | Search the real sub-problem: repeat N times without loops |
| 4 | 18 Oct 2026 | Consider recursion, template recursion, goto copies | Forbidden, or only work for a fixed size | Check every idea against every rule before spending time on it |
| 5 | 20 Oct 2026 | Mutual function calls (A calls B, B calls A) | Forms a cycle on the call stack; it is indirect recursion | Mutual calls are recursion in disguise; strictly forbidden |
| 6 | 22 Oct 2026 | Using `new Inner[...]` without `delete[]` | Leaks heap memory on every inner iteration | Use `delete[] new Inner[...]` to invoke constructors while instantly freeing heap memory |
| 7 | 23 Oct 2026 | Ignoring swap parameters in `swap(int &x, int &y)` | Code relied directly on global indices rather than references | Always cleanly pass and swap references |
| 8 | 24 Oct 2026 | Printing results in `main()` with a `for` loop | Teacher might disqualify code if ANY loop exists in the file | Use a `Printer` object with constructors to eliminate loops 100% |
| 9 | 24 Oct 2026 | Version 6 matrix: only checking `A[i] > A[j]` | Fails on duplicate numbers because equal elements get the exact same rank | Add a tie-breaker `(A[i] == A[j] && i > j)` to ensure unique, stable ranks |
| 10 | 24 Oct 2026 | Thinking sorting only works in 1D sequential steps | Traps the mind into needing loops | A 2D grid of booleans (Boolean Matrix) sorts elements by computing ranks directly |
