class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        long long ans = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                count++;
            }
            else{
                ans += (count * (count+1)) / 2;
                count = 0;
            }
        }
        if(count != 0){
            ans += (count * (count+1)) / 2;
        }
        return ans;
    }
};