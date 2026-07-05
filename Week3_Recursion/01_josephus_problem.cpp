#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    if (n == 1) return 0;
    return (josephus(n - 1, k) + k) % n;
}

int josephus_iterative(int n, int k) {
    int survivor = 0;
    for (int i = 2; i <= n; i++)
        survivor = (survivor + k) % i;
    return survivor;
}

int main() {
    int n = 7, k = 3;
    cout << "Josephus(" << n << ", " << k << ") = "
         << josephus(n, k) << " (0-indexed)\n";
    cout << "Iterative: " << josephus_iterative(n, k) << "\n";
    return 0;
}
