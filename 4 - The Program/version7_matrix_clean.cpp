// Version 7: Boolean Comparison Matrix Sort (Handling Duplicates & Edge Cases)
// Changes from version 6:
// 1. Handled duplicate values: if arr[i] == arr[j], break the tie using (i > j).
// 2. Handled edge cases: arrays of size 0 or 1.
// 3. Made it a clean reusable function without using std::vector.

#include <iostream>

void booleanMatrixSort(int input[], int output[], int size);

// Pointers and state for the constructors
int *in_ptr = nullptr;
int *out_ptr = nullptr;
int n_size = 0;
int row_idx = 0;
int col_idx = 0;
int calculated_rank = 0;

// Cell compares element at row_idx with element at col_idx
struct MatrixCell {
    MatrixCell() {
        // Boolean comparison logic:
        // A number is placed after another if:
        // - it is strictly greater, OR
        // - it is equal but came after it in the original array (i > j)
        bool greater = (in_ptr[row_idx] > in_ptr[col_idx]);
        bool tie_breaker = (in_ptr[row_idx] == in_ptr[col_idx]) && (row_idx > col_idx);

        if (greater || tie_breaker) {
            calculated_rank++;
        }
        col_idx++;
    }
};

// Row computes the final rank for element at row_idx
struct MatrixRow {
    MatrixRow() {
        col_idx = 0;
        calculated_rank = 0;

        // Run all cells in this row
        delete[] new MatrixCell[n_size];

        // Place element directly in its final position
        out_ptr[calculated_rank] = in_ptr[row_idx];
        row_idx++;
    }
};

void booleanMatrixSort(int input[], int output[], int size) {
    if (size <= 0) return;
    if (size == 1) {
        output[0] = input[0];
        return;
    }

    in_ptr = input;
    out_ptr = output;
    n_size = size;
    row_idx = 0;

    // Run all rows
    delete[] new MatrixRow[size];
}

int main() {
    // Test with duplicate numbers and negative numbers
    int input[] = {5, 2, 9, 2, -3, 5, 0};
    int size = sizeof(input) / sizeof(input[0]);
    int output[7];

    std::cout << "Original array with duplicates: 5 2 9 2 -3 5 0" << std::endl;

    booleanMatrixSort(input, output, size);

    std::cout << "Sorted array (v7 clean):        ";
    for (int k = 0; k < size; k++) {
        std::cout << output[k] << " ";
    }
    std::cout << std::endl;

    return 0;
}
