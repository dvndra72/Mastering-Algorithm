#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++)
        for (int j = W; j >= wt[i]; j--)  
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);

    return dp[W];
}

bool subsetSum(vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int x : nums)
        for (int j = target; j >= x; j--)
            dp[j] = dp[j] || dp[j - x];

    return dp[target];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (c <= i && dp[i - c] != INT_MAX)
                dp[i] = min(dp[i], dp[i - c] + 1);

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int lcs(string& a, string& b) {
    int m = a.size(), n = b.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1])
                curr[j] = prev[j-1] + 1;
            else
                curr[j] = max(prev[j], curr[j-1]);
        }
        swap(prev, curr);
    }

    return prev[n];
}

int editDistance(string& a, string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j],      
                                     dp[i][j-1],      
                                     dp[i-1][j-1]});  
        }
    }

    return dp[m][n];
}

int main() {
    
    vector<int> wt = {1, 3, 4, 5}, val = {1, 4, 5, 7};
    cout << "Knapsack(W=7): " << knapsack(wt, val, 7) << "\n";

    
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    cout << "SubsetSum(9): " << (subsetSum(nums, 9) ? "YES" : "NO") << "\n";

    vector<int> coins = {1, 5, 10, 25};
    cout << "CoinChange(30): " << coinChange(coins, 30) << "\n";

    string s1 = "abcde", s2 = "ace";
    cout << "LCS: " << lcs(s1, s2) << "\n";

    string w1 = "horse", w2 = "ros";
    cout << "EditDistance: " << editDistance(w1, w2) << "\n";

    return 0;
}
