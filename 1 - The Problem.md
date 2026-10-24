# 1 - The Problem

## What the teacher asked

Write a **selection sort** algorithm in **C++/c/pcudo code** with:
- no loops
- no recursion
- no goto

The size of the array is N items.

The teacher also said this problem was given in a PhD algorithms exam (not verified yet if they give the answer ro not).

## The hints

1. (18/10/2026) The algorithm contines **booleans**.

## What selection sort does (sorting algorithm im gonna use)

1. Look at the part of the array that is not sorted yet.
2. Find the smallest element in it.
3. Swap it with the first element of that part.
4. Move one position forward and repeat until the end.

Example: `5 2 9 1 7` becomes `1 2 9 5 7`, then `1 2 9 5 7` (2 stays), then `1 2 5 9 7`, then `1 2 5 7 9`.

## The rules in short

- Repetition is needed (selection sort repeats a lot), but I cannot use loops, recursion or goto.
- The size is not known (N) when I write the code.
- Booleans should be part of the solution.

## What I do not understand yet

- How can anything repeat without a loop or recursion?
- What exactly does the teacher mean by "use booleans"?