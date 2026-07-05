#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long, long long>> pts(n);
        for (auto& [x, y] : pts) cin >> x >> y;

        long long maxDistSq = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long dx = pts[i].first - pts[j].first;
                long long dy = pts[i].second - pts[j].second;
                maxDistSq = max(maxDistSq, dx * dx + dy * dy);
            }
        }
        cout << maxDistSq << "\n";
    }

    return 0;
}
