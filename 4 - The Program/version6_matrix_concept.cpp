// Version 6: Boolean Comparison Matrix Sort (First Prototype)
// Story / Inspiration:
// I was walking in the university hallway and looking at the floor tiles (carrelage).
// The square tiles formed a grid (N x N).
// I thought: what if instead of searching for the minimum one by one in a loop,
// we compare every number with every other number in a grid of booleans?
// If number A is bigger than 3 numbers, its rank in the sorted array is 3!
// No loops, no recursion.

#include <iostream>

int arr[] = {7, 2, 9, 1};
int sorted_arr[4];
int n = 4;
int i = 0;
int j = 0;
int current_rank = 0;

// Cell represents one square (i, j) in the grid
struct Cell {
    Cell() {
        // Boolean comparison between element i and element j
        bool is_greater = (arr[i] > arr[j]);
        if (is_greater) {
            current_rank++;
        }
        j++;
    }
};

// Row represents row i in the grid
struct Row {
    Row() {
        j = 0;
        current_rank = 0;

        // Run n cells for this row
        delete[] new Cell[n];

        // Put arr[i] directly into its sorted rank!
        sorted_arr[current_rank] = arr[i];
        i++;
    }
};

int main() {
    std::cout << "Original array: 7 2 9 1" << std::endl;

    // Run n rows of the grid
    delete[] new Row[n];

    std::cout << "Sorted array (v6 matrix): ";
    for (int k = 0; k < n; k++) {
        std::cout << sorted_arr[k] << " ";
    }
    std::cout << std::endl;

    // Note: This prototype works for unique numbers,
    // but if two numbers are equal, they will get the same rank!
    // We will fix duplicates in version 7.
    return 0;
}
