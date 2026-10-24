# Selection Sort Without Loops, Recursion or goto

**Name:** Aouine Nasim   **Course:** ADS   **Teacher:** L.lamiche   **Date:** 18/10/2026

---
### Aleart: Click any blue words to go to its file


## 1. The Problem
I created a md file [The problem](</1 - The Problem.md>) explaing the problem and the task and all the hints i got and break down how it gonna or should work and the input and the output.
## 2. The language
For this problem im gonna use **C++**.

## 3. How I Searched
I created [Reserch map](</2 - Research map.md>) md file to contruls how to surch etc and writing all things that i found or made to find out any cloe to the solution


## 6. Programs I made and what I learned



**[version1.cpp](</4 - The Program/version1.cpp>)** `[state:failed]` `[rules:recursion]`
- What I did: repetition using functions that call each other.
- What I learned: functions calling each other make a cycle, so it is recursion.

**[version2.cpp](<4 - The Program/version2.cpp>)** `[state:works]` `[rules:ok]`
- What I did: a simple repetition using only constructors.
- What I learned: constructions in oop

**[version3.cpp](<4 - The Program/version3.cpp>)** `[state:works]` `[rules:ok]`
- What I did: a second simple repetition, connected to the first.
- What I learned: conecting construction and understanding the consept of making objects using constructions.

**[version4.cpp](<4 - The Program/version4.cpp>)** `[state:works]` `[rules:ok]`
- What I did: changed version 3 to make an n x n grid.
- What I learned: understanding more how consstruction works

**[final_version.cpp](<4 - The Program/final_version.cpp>)** `[state:final]` `[rules:ok]`
- What I did: testing all arrays output affter calling the sorting function.
- What I learned: sorting any array of N items without using any loop or recrusion and using construcions with ease.

## 5. Tests

**Program**: `4 - The Program/final_version.cpp`.

**Compiler**: `g++ -std=c++17 -Wall`.

**Compilation and Execution:**

```bash
g++ -std=c++17 -Wall "4 - The Program/final_version.cpp" -o final_version
./final_version
```


| # | Input | Expected | Output | Result |
|---|---|---|---|---|
| 1 | `5 5 2 9 1 7` | `1 2 5 7 9` | `1 2 5 7 9` | PASS |
| 2 | `42` (one element) | `42` | `42` | PASS |
| 3 | `3 3 1 2` (repeated values) | `1 2 3 3` | `1 2 3 3` | PASS |
| 4 | `6 9 8 7 6 5 4` (reverse order) | `4 5 6 7 8 9` | `4 5 6 7 8 9` | PASS |
| 5 | `3 -1 -5 0` (negative numbers) | `-5 -1 0 3` | `-5 -1 0 3` | PASS |
| 6 | `0` (Empty array) | No elements | No elements | PASS |

## 7. Limits and Honest Discussion
What the program cannot do (global variables, one sort at a time) and the honest point that the repetition is hidden inside how C++ builds arrays of objects. i dont knpw yet if it will work using psudo code as well or not.

## 8. Sources
- Chatgpt
- Youtub
- google
- OOP book

| Date | Source | Where I found it | What it gave me 
|---|---|---|---|
| 19 Oct 2026 | GeeksforGeeks: Print a character n times without using loop, recursion or goto in C++ | web search | the trick of using the constructor of each object in an array 
| 19 Oct 2026 | Youtub: Full vedio about constructions | AI search | an array of objects calls the constructor n times 
| 19 Oct 2026 | Microsoft Learn blog: C++ Weird looping mechanism | web search | an array of objects calls the constructor n times 
| 21 Oct 2026 | GeeksforGeeks: How to print N times without using loops or recursion | web search | same idea with a runtime N 
| 21 Oct 2026 | Codeforces blog entry 105832 | web search | a copy-and-goto approach (not allowed)
| 21 Oct 2026 | CodeGuru forum: bubble sort with no loops | web search | answers that use recursion (not allowed) 
| 23 Oct 2026 | Full understanding of constructions | web search | creating N objects without loops or recrusion (allowed) 

