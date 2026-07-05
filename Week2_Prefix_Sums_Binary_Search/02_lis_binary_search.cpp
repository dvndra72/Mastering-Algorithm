#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;

    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);

        if (it == tails.end()) {
            tails.push_back(x);   
        } else {
            *it = x;              
        }
    }

    return tails.size();
}
vector<int> findLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> tails, tail_idx, parent(n, -1);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
        int pos = it - tails.begin();

        if (it == tails.end()) {
            tails.push_back(nums[i]);
            tail_idx.push_back(i);
        } else {
            *it = nums[i];
            tail_idx[pos] = i;
        }

        parent[i] = (pos > 0) ? tail_idx[pos - 1] : -1;
    }

    vector<int> lis;
    for (int i = tail_idx.back(); i != -1; i = parent[i])
        lis.push_back(nums[i]);
    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "LIS Length: " << lengthOfLIS(nums) << "\n";

    auto lis = findLIS(nums);
    cout << "LIS: ";
    for (int x : lis) cout << x << " ";
    cout << "\n";

    return 0;
}
