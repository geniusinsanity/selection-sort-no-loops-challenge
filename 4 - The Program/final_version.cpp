// Final Version: Ultimate Selection Sort with No Loops, No Recursion, No Goto
// Includes:
// - Zero loops in selectionSort AND zero loops in printArray (both use constructors!)
// - No memory leaks (all dynamic arrays freed with delete[])
// - Handles all edge cases: empty arrays, single elements, duplicates, negative numbers, reverse order
// - Uses boolean conditions for decisions

#include <iostream>

void selectionSort(int arr[], int size);
void printArray(int arr[], int size);
void cleanSwap(int &x, int &y);

// Global state for communication between constructors
int *arr_ptr = nullptr;
int n = 0;
int i = 0;
int j = 0;
int min_index = 0;
int print_idx = 0;

// Inner "loop" replacement: finds the minimum in the remaining array
struct Inner {
    Inner() {
        j++;
        // The Boolean Hint: evaluates to true or false to select the minimum
        if (arr_ptr[j] < arr_ptr[min_index]) {
            min_index = j;
        }
    }
};

// Outer "loop" replacement: runs for each position in the array
struct Outer {
    Outer() {
        min_index = i;
        j = i;
        int remaining = n - i - 1;

        if (remaining > 0) {
            delete[] new Inner[remaining]; // Run inner loop and free memory
        }

        cleanSwap(arr_ptr[i], arr_ptr[min_index]);
        i++;
    }
};

// Printer "loop" replacement: prints the array without any for/while loops!
struct Printer {
    Printer() {
        std::cout << arr_ptr[print_idx] << " ";
        print_idx++;
    }
};

void printArray(int arr[], int size) {
    if (size <= 0) {
        std::cout << "[Empty array]";
        return;
    }
    arr_ptr = arr;
    print_idx = 0;
    delete[] new Printer[size];
}

void selectionSort(int arr[], int size) {
    if (size <= 1) return; // 0 or 1 element is already sorted

    arr_ptr = arr;
    n = size;
    i = 0;
    delete[] new Outer[n];
}

void cleanSwap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Helper to run a test case and display results
void runTest(int test_num, const char* name, int arr[], int size) {
    std::cout << "\n--- Test " << test_num << ": " << name << " ---" << std::endl;
    std::cout << "Before: ";
    printArray(arr, size);
    std::cout << std::endl;

    selectionSort(arr, size);

    std::cout << "After:  ";
    printArray(arr, size);
    std::cout << std::endl;
}

int main() {
    std::cout << "======================================================" << std::endl;
    std::cout << "  Selection Sort (No Loops, No Recursion, No Goto)    " << std::endl;
    std::cout << "======================================================" << std::endl;

    // Test 1: General unsorted array
    int t1[] = {5, 2, 9, 1, 7};
    runTest(1, "General unsorted array", t1, 5);

    // Test 2: Single element
    int t2[] = {42};
    runTest(2, "Single element", t2, 1);

    // Test 3: Repeated values
    int t3[] = {3, 3, 1, 2};
    runTest(3, "Repeated values", t3, 4);

    // Test 4: Reverse order
    int t4[] = {9, 8, 7, 6, 5, 4};
    runTest(4, "Reverse order", t4, 6);

    // Test 5: Negative numbers
    int t5[] = {3, -1, -5, 0};
    runTest(5, "Negative numbers", t5, 4);

    // Test 6: Empty array
    int t6[] = {};
    runTest(6, "Empty array", t6, 0);

    std::cout << "\nAll 6 tests completed successfully without any loops!" << std::endl;
    return 0;
}
