// Alternative Solution in pure C using <setjmp.h>
// This solves the problem for C (where C++ constructors do not exist).
// It uses setjmp/longjmp for control-flow jumps instead of loops, recursion, or goto.
// It uses booleans (arr[j] < arr[min_idx]) to find the minimum.

#include <stdio.h>
#include <setjmp.h>

void selectionSortC(int arr[], int n) {
    if (n <= 1) return;

    jmp_buf outer_env;
    jmp_buf inner_env;

    int i = 0;
    int j = 0;
    int min_idx = 0;

    // Outer loop replacement: jumps back to outer_env until i == n - 1
    setjmp(outer_env);
    if (i < n - 1) {
        min_idx = i;
        j = i + 1;

        // Inner loop replacement: jumps back to inner_env until j == n
        setjmp(inner_env);
        if (j < n) {
            // The Boolean condition:
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            j++;
            longjmp(inner_env, 1); // Jump back to inner_env without loops, recursion or goto
        }

        // Swap arr[i] with arr[min_idx]
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        i++;
        longjmp(outer_env, 1); // Jump back to outer_env without loops, recursion or goto
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, -5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array (C solution):\n");
    for (int k = 0; k < n; k++) printf("%d ", arr[k]);
    printf("\n");

    selectionSortC(arr, n);

    printf("Sorted array with setjmp/longjmp:\n");
    for (int k = 0; k < n; k++) printf("%d ", arr[k]);
    printf("\n");

    return 0;
}
