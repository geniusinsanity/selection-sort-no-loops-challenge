
#include <iostream>

int arr[] = {5, 2, 9, 1, 7};
int n = 5;

int j = 0;          // Current position in the array
int min_idx = 0;    // Position of the smallest value found so far

void stepB(); // I declared B first because I will call it inside A


void stepA()
{
    // I used this condition to control when the repetition should stop.
    // As long as j is smaller than n, I still have elements to check.

    if (j < n)
    {
        // Compare the current element with the smallest one found so far.
        // If the current element is smaller, I update min_idx.

        if (arr[j] < arr[min_idx])
        {
            min_idx = j;
        }

        // Move to the next position in the array.
        j++;

        // Instead of using a loop, I tried to continue the process
        // by calling another function.

        stepB();
    }
}


void stepB()
{
    // Here I call A again to repeat the same process.
    // A will check the condition and process the next element.

    stepA();

    // The problem is that A calls B, and B calls A again.
    // This creates a cycle of function calls.
}


int main()
{
    std::cout << "Trying to repeat the process without using loops..."
              << std::endl;

    // Start the process.
    stepA();

    // Display the smallest value found after checking the array.
    std::cout << "Smallest value found: " << arr[min_idx] << std::endl;
    std::cout << "Its index: " << min_idx << std::endl;

    return 0;
}
