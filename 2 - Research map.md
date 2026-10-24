# 2b - Research Map

This map shows the path of the research starting at 18/10/2026, including the wrong turns. Stages 0 and 2 are currently done. Stages 3 to 7 are still to do.

### resorces:
```
Chat jpt -- Youtub -- Google -- Reasurchgate -- 
```
  

## The map

```
  ----------------------------------------
  | 0. I trtied to find/make   [DONE]    |
  |    any solutionIts but i stuck       |
  |    repetition.                       |
  ----------------------------------------
                     |
                     v
  ----------------------------------------
  | 1. Asked an AI tool        [DONE]    |
  |    Its answer: impossible            |
  ----------------------------------------
                     |
                     v
  ----------------------------------------
  | 2. Searched uses of booleans:[DONE]  |
  |    Found nothing useful              |
  ----------------------------------------
                     |
                     v
  ---------------------------------------- <------
  | 3. Search all kinds of loops         |       |
  |    and what can replace them         |       |
  ----------------------------------------       |
                     |                           |
                     v                           |
  ----------------------------------------       |
  | 4. Test each idea found              |       |
  |                                      |       |
  ----------------------------------------       |
                     |                           |
                     v                           |
  (Fits all rules and any size)?  -- NO ---------
                     |
                    YES
                     |
                     v
  ----------------------------------------
  | 5. Build the program                 |
  |    Boolean decides, trick repeats    |
  ----------------------------------------
                     |
                     v
  ----------------------------------------
  | 6. Test it                           |
  |    Edge cases, record every error    |
  ----------------------------------------
                     |
                     v
  ----------------------------------------
  | 7. Write the final report            |
  |    Including the wrong turns         |
  ----------------------------------------
```

`[DONE]`The stage it is allready finished before i started yet.
 The line with `?` in the end it repreients a decision. If the answer is NO, the line on the right goes back up to stage 3. If the answer is YES, move on to stage 5.


The rules for the decision box: no loop, no recursion, no goto, uses a boolean, works for any array and any `size` given in the code.

---

## Stage 0: Tried it myself (DONE)

- **Goal:** See if I could solve the problem alone, before asking an AI or searching.
- **What I tried:** I thought it could be done by controlling i and j, but the problem of repetition came with no solution from my own knowledge and experience. After 2 days I gave up and went directly to stage 1.

- **Next step:** asking AI tools to get any help.

## Stage 1: Asked an AI tool (DONE)

- **Goal:** see if the problem can be solved at all.
- **What happened:** the AI said it is impossible.
  > He said it is impossible. I insist under which exact assumptions is it impossible? Is there any feature in C/C++ that makes code run more than once without a for/while/do loop, recursion or goto?. No any usfull information yet.

- **Next step:** tell the teahcer it was impossible

## `First hint`:

## Stage 2: Searched uses of booleans (DONE)

- **Goal:** find how booleans could help the algorithm.
- **What happened:** found nothing useful.
- > a boolean gives a decision (true or false), it does not repeat anything. but the algorithm contines boolean so this is our first step

## Stage 3: Search all kinds of loops and what can replace them (TO DO)

- **Goal:** list every way code can run more than once, then mark which ones the teacher's rules forbid.
- **Where i looked:** C/C++ youtub vedios and cppreference, reasurchgate, AI tools.
- **Prompt 1 (the full list):**
  > List every mechanism in C/C++ that makes code run more than once exept(loops, recursion, goto).
- **Search words for Google:** repeat N times without loops recursion goto.

## Stage 4: Test each idea found (TO DO)

- **Goal:** for each idea from stage 3, check it against the rules and the size.
- **Questions to ask about every idea:**
  1. Does it use a loop, recursion or goto, even hidden in my own code?
  2. Does it work when the size is a variable?
  3. Can a boolean make the decision inside it?
- **Example idea to check:** sorting networks (a fixed list of compare-and-swap steps).
  > Explain sorting networks. Do they work when the array size is only known at runtime? Why or why not?
- **Verify prompt (use on every answer):**
  > What is wrong or weak in your answer? What would a teacher challenge?
- **Write in the Day note:** every idea, the verdict (fits or fails), and the reason. Failed ideas go in `6 - Mistakes and Lessons.md`.

### Decision: does it fit all the rules and any size?

- **No:** go back to stage 3 and search again. Write what you learned from the failure.
- **Yes:** go to stage 5.

## Stage 5: Build the program (TO DO)

- **Goal:** write selection sort with the idea that passed, with a boolean making the decision.
- **Setup from the teacher:** `int array[] = {...}; int size = ...;` written in the code.
- **Prompt:**
  > Write selection sort in C- for `int array[]` and `int size`, with no for/while/do, no recursion and no goto, using a boolean for the comparison. Explain every line, and tell me which part repeats and which part decides.
- **Write in the Day note:** each version of the program, what changed, and why.
- **Files:** save every version in `4 - The Program`.

## Stage 6: Test it (TO DO)

- **Goal:** make sure it is right, and find the mistakes before the teacher does.
- **Prompt:**
  > Give me edge-case tests for a sort function on an int array: empty, one element, repeated values, negative numbers, reversed, already sorted, large size. Tell me what each case checks.
- **Rule:** run the tests myself on my own computer. Do not copy results from an AI.
- **Write in:** `5 - Tests.md`. Every failure goes in `6 - Mistakes and Lessons.md`.

## Stage 7: Write the final report (TO DO)

- **Goal:** a report the teacher can read from start to end.
- **Prompt:**
  > Check this report outline. Does it show the problem, the research path with the wrong turns, the solution, the tests, the limits and the sources? What is missing?
- **Write in:** `8 - Final Report.md`, built from files 1 to 7.
- **Before handing in:** ask the teacher where the PhD-exam claim comes from, and write the answer in `7 - Sources and AI Questions.md`.