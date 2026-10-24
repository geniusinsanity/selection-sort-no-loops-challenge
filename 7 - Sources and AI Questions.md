# 7 - Sources and AI Questions

## Sources

| Date | Source | Where I found it | What it gave me | How much I trust it |
|---|---|---|---|---|
| 18 Oct 2026 | GeeksforGeeks: Print a character n times without using loop, recursion or goto in C++ | web search | the trick of using the constructor of each object in an array | tutorial site, and I tested my own code |
| 18 Oct 2026 | Microsoft Learn blog: C++ Weird looping mechanism | web search | an array of objects calls the constructor n times | personal blog on a Microsoft site |
| 18 Oct 2026 | GeeksforGeeks: How to print N times without using loops or recursion | web search | same idea with a runtime N | tutorial site |
| 18 Oct 2026 | Codeforces blog entry 105832 | web search | a copy-and-goto approach (not allowed here) | community blog |
| 18 Oct 2026 | CodeGuru forum: bubble sort with no loops | web search | answers that use recursion (not allowed) | forum |

### Not verified
- The teacher's statement that this problem was in a PhD exam. I found no source. Ask the teacher where it comes from.

## Questions I asked an AI tool (Claude, 18 Oct 2026)

Rule: nothing goes in the final report as a fact until I tested it or found a source.

| # | My question | Short answer | What I understood | Checked? |
|---|---|---|---|---|
| 1 | Can I make a loop using only booleans? | No. It needs memory/feedback, time, or self-reference | Booleans decide, they do not repeat | Theory only |
| 2 | Is it booleans plus something else? | Yes: a clock, memory feedback, or recursion | Matches how I read the hint | Theory only |
| 3 | How do I use a sorting network? | A fixed list of compare-and-swap steps | Works only for a fixed size | Idea only, not run |
| 4 | How to sort with a runtime size and no loop, recursion or goto? | Use `new Class[n]` so the constructor runs n times | This became program version 1 | Compiled and tested (5 tests passed) |
| 5 | Can it sort an existing array? | Yes: point `a` to it, set `n`, reset `i = 0` | A reusable function is possible | Not tested yet |
| 6 | What is the role of the boolean? | The comparison `a[j] < a[mn]` picks the smallest | Boolean = decision, constructors = repetition | Traced by hand on an example |
