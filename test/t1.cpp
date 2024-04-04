#include <iostream>
#include <cmath>
using namespace std;

int findMinimumLastElement(int X, int n) {
    if (X == 1) {
        return 1; // Special case for X = 1
    }

    int current = X;

    // Optimized approach inspired by the Java code:
    // Start with X and try to reduce it while maintaining X as its bitwise AND
    for (int bit = 30; bit >= 0; bit--) {
        if ((X & (1 << bit)) != 0) {
            // Check if we can subtract 2^bit without violating the bitwise AND condition
            int trial = current - (1 << bit);
            if ((trial & X) == X && trial >= n) {
                current = trial; // Update if successful
            }
        }
    }

    // Iteratively adjust to satisfy increasing order constraint
    for (int i = n - 1; i > 0; i--) {
        while ((current & X) != X || current <= (1 << i) - 1) {
            current--;
        }
    }

    return current;
}

int main() {
    int X, n;
    cout << "Enter X and n: ";
    cin >> X >> n;

    int minLastElement = findMinimumLastElement(X, n);
    cout << "Minimum possible value of the last element: " << minLastElement << endl;

    return 0;
}