
#include <iostream>

// This version focus on how constructors work
// and how they can be used to simulate a simple loop.

int j = 0;       // Index of the next array element to fill
const int n = 4; // Number of elements in the array
int array[n];    // Global array accessible from both structs

// Fills one array element each time the constructor is called
struct loop2 {
    loop2() {
        array[j] = j; // Store the current index in the array
        j++;          // Move to the next array index
    }
};

// Creates n loop2 objects to fill the entire array
struct loop1 {
    loop1() {
        // Dynamically create an array of n loop2 objects.
        // Each object automatically calls its constructor.
        new loop2[n];
    }
};

int main() {
    // Create a loop1 object to start the array-filling process
    loop1 x;

    // Print all elements of the array
    for (int i = 0; i < n; i++) {
        std::cout << array[i];
    }
}