#include <iostream>

// Version 3: Nested loop simulation with constructors
// Goal: Connect two constructors where the outer one creates a dynamic number of inner ones.
// State: WORKS (Rules: OK)
// What I learned: We can pass variable counts (like n - i - 1) to inner constructors.

int i_counter = 0;
int total_steps = 0;
const int n = 4;

struct InnerLoop {
    InnerLoop() {
        total_steps++;
        std::cout << "  Inner step executed (total: " << total_steps << ")" << std::endl;
    }
};

struct OuterLoop {
    OuterLoop() {
        std::cout << "Outer step i = " << i_counter << std::endl;
        // Dynamically create inner objects for this outer step
        int inner_count = n - i_counter - 1;
        if (inner_count > 0) {
            new InnerLoop[inner_count];
        }
        i_counter++;
    }
};

int main() {
    std::cout << "Starting nested constructor test with n = " << n << std::endl;
    new OuterLoop[n];
    std::cout << "Finished! Total inner steps: " << total_steps << std::endl;
    return 0;
}
