// Version 5: Fixing Memory Leaks & Refining Logic
// Based on review and AI feedback:
// 1. FIXED MEMORY LEAK: Replaced 'new Inner[count]' with 'delete[] new Inner[count]'.
//    This creates the objects (running their constructors), and then immediately frees the memory!
// 2. FIXED SWAP: Cleaned up swap(x, y) to actually use the references passed to it.
// 3. FIXED REUSABILITY: Reset all counters properly so selectionSort can be called multiple times.
// 4. EDGE CASES: Added checks for n <= 1 so it doesn't allocate negative or unnecessary objects.

#include <iostream>

void selectionSort(int arr[], int size);
void cleanSwap(int &x, int &y);

// Global pointers and state variables for constructor communication
int *arr_ptr;
int n, i, j, min_index;

struct Inner {
    Inner() {
        j++;
        // The Boolean Hint from teacher:
        // (arr_ptr[j] < arr_ptr[min_index]) evaluates to true (1) or false (0).
        // It decides whether to update the minimum index.
        if (arr_ptr[j] < arr_ptr[min_index]) {
            min_index = j;
        }
    }
};

struct Outer {
    Outer() {
        min_index = i;
        j = i;
        int remaining = n - i - 1;
        
        // AI Note: If remaining > 0, allocate and immediately delete to prevent memory leak!
        if (remaining > 0) {
            delete[] new Inner[remaining]; // constructor runs 'remaining' times, then deletes cleanly
        }

        // Swap the found minimum element with current position
        cleanSwap(arr_ptr[i], arr_ptr[min_index]);
        i++;
    }
};

int main() {
    int array[] = {64, 25, 12, 22, 11, -3, 0, 99};
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Original array: 64 25 12 22 11 -3 0 99" << std::endl;
    selectionSort(array, size);

    std::cout << "Sorted array (v5): ";
    for (int k = 0; k < size; k++) {
        std::cout << array[k] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void selectionSort(int arr[], int size) {
    if (size <= 1) return; // Edge case: 0 or 1 element is already sorted

    arr_ptr = arr;
    n = size;
    i = 0;
    
    // AI Note: delete[] new Outer[n] ensures Outer constructors run n times,
    // and no leaked heap memory remains when done!
    delete[] new Outer[n];
}

void cleanSwap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
