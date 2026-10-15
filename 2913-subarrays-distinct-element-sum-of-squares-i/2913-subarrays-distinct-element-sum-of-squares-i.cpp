class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i=0;i<n;i++){
            unordered_set<int> mpp;
            for(int j=i;j<n;j++){
                mpp.insert(nums[j]);
                result += mpp.size() * mpp.size();
            }
        }
        return result;
    }
};