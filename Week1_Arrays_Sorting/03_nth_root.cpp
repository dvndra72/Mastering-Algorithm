#include <bits/stdc++.h>
using namespace std;
int power_compare(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    int lo = 1, hi = m;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cmp = power_compare(mid, n, m);

        if (cmp == 1) return mid;       
        else if (cmp == 0) lo = mid + 1; 
        else hi = mid - 1;             
    }

    return -1;
}
