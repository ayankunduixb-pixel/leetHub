class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int currentSum = accumulate(nums.begin(), nums.end(), 0);
        int totalSum = n * (n + 1) / 2;

        return totalSum - currentSum;
    }
};