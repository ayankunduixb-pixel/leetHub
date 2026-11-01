class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int mini = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            mini = min(nums[i],mini);
        }
        return sum - nums.size() * mini;
    }
};