# 5 - Tests

This document records the exact test cases run on the final program (`4 - The Program/final_version.cpp`).

## Compilation Command

Compiled with standard C++17 and strict warnings enabled:

```bash
g++ -std=c++17 -Wall -Wextra "4 - The Program/final_version.cpp" -o final_version
./final_version
```

## Test Results Table

| # | Test Case Description | Input Array | Expected Output | Actual Output | Status |
|---|---|---|---|---|---|
| 1 | General unsorted array | `5 2 9 1 7` | `1 2 5 7 9` | `1 2 5 7 9` | **PASS** |
| 2 | Single element (size = 1) | `42` | `42` | `42` | **PASS** |
| 3 | Repeated / duplicate values | `3 3 1 2` | `1 2 3 3` | `1 2 3 3` | **PASS** |
| 4 | Reverse sorted order | `9 8 7 6 5 4` | `4 5 6 7 8 9` | `4 5 6 7 8 9` | **PASS** |
| 5 | Negative numbers & zero | `3 -1 -5 0` | `-5 -1 0 3` | `-5 -1 0 3` | **PASS** |
| 6 | Empty array (size = 0) | `[]` | `[Empty array]` | `[Empty array]` | **PASS** |

## Detailed Terminal Output

```text
======================================================
  Selection Sort (No Loops, No Recursion, No Goto)    
======================================================

--- Test 1: General unsorted array ---
Before: 5 2 9 1 7 
After:  1 2 5 7 9 

--- Test 2: Single element ---
Before: 42 
After:  42 

--- Test 3: Repeated values ---
Before: 3 3 1 2 
After:  1 2 3 3 

--- Test 4: Reverse order ---
Before: 9 8 7 6 5 4 
After:  4 5 6 7 8 9 

--- Test 5: Negative numbers ---
Before: 3 -1 -5 0 
After:  -5 -1 0 3 

--- Test 6: Empty array ---
Before: [Empty array]
After:  [Empty array]

All 6 tests completed successfully without any loops!
```

## Observations
- No memory leaks detected.
- The `Printer` object successfully printed every array element using constructor repetition instead of `for`/`while`.
- Edge cases (size 0 and size 1) returned immediately without illegal pointer or index access.
