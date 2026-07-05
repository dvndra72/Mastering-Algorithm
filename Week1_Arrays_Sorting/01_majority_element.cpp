class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};

class SolutionFollowUp {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 1, cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
            else if (cnt1 == 0) { cand1 = x; cnt1 = 1; }
            else if (cnt2 == 0) { cand2 = x; cnt2 = 1; }
            else { cnt1--; cnt2--; }
        }
        cnt1 = cnt2 = 0;
        for (int x : nums) {
            if (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
        }

        vector<int> res;
        int n = nums.size();
        if (cnt1 > n / 3) res.push_back(cand1);
        if (cnt2 > n / 3) res.push_back(cand2);
        return res;
    }
};
