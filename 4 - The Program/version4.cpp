// Version 4: First working Selection Sort with constructors and booleans
// State: WORKS (Rules: OK, but has memory leak and imperfect swap)
// The boolean (arr_ptr[j] < arr_ptr[min_index]) decides the minimum.
// Repetition comes from new Inner[n - i - 1] and new Outer[n].

#include <iostream>

void swap(int &x, int &y);
void selectionSort(int arr[], int size);

int *arr_ptr, n, i, j, min_index;

struct Inner { // inner "loop": runs n-i-1 times
    Inner() {
        j++;
        if (arr_ptr[j] < arr_ptr[min_index]) { // boolean decision
            min_index = j;
        }
    }
};

struct Outer { // outer "loop": runs n times
    Outer() {
        min_index = i;
        j = i;
        // NOTICE: Allocating with new without delete[] causes a memory leak!
        // We will fix this in version 5.
        if (n - i - 1 > 0) {
            new Inner[n - i - 1];
        }
        swap(arr_ptr[i], arr_ptr[min_index]);
        i++;
    }
};

int main() {
    int array[] = {2, 5, 333, 1, 6, 4, 12, 93, 0, 3, 3, 23, 54, 200};
    int size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);

    // Printing with for loop in main for quick testing
    for (int k = 0; k < size; k++) {
        std::cout << array[k] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void selectionSort(int arr[], int size) {
    arr_ptr = arr;
    n = size;
    i = 0;
    new Outer[n];
}

void swap(int &x, int &y) {
    // Notice: ignores x and y, uses globals directly (fixed in v5)
    int temp = arr_ptr[i];
    arr_ptr[i] = arr_ptr[min_index];
    arr_ptr[min_index] = temp;
}
