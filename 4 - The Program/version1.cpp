// Version 1: First attempt to repeat without loops
// Idea: Function A calls Function B, and Function B calls Function A
// State: FAILED (Violates rules: Indirect / Mutual Recursion)
// Lesson: Even if a function doesn't call itself directly, 
// a cycle of function calls is still recursion on the call stack!

#include <iostream>

int arr[] = {5, 2, 9, 1, 7};
int n = 5;
int i = 0, j = 0, min_idx = 0;

void stepB();

void stepA() {
    if (j < n) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
        j++;
        stepB(); // calls B
    }
}

void stepB() {
    stepA(); // calls A back (creates a cycle!)
}

int main() {
    std::cout << "Attempting repetition with mutual function calls..." << std::endl;
    // This is indirect recursion! The teacher and compiler will reject this as recursion.
    // That's why version 1 failed.
    return 0;
}