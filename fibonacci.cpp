#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0; // Base case: F(0) = 0
    if (n == 1) return 1; // Base case: F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << "F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
