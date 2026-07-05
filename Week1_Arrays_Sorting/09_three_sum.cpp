class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int lo = i + 1, hi = n - 1;
            int target = -nums[i];

            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                if (sum == target) {
                    result.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++;
                    hi--;
                } else if (sum < target) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }

        return result;
    }
};



class SolutionFollowUp {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int lo = j + 1, hi = n - 1;
                long long t = (long long)target - nums[i] - nums[j];

                while (lo < hi) {
                    long long sum = nums[lo] + nums[hi];
                    if (sum == t) {
                        result.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++;
                        hi--;
                    } else if (sum < t) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }

        return result;
    }
};
