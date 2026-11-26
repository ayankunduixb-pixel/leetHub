class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        int countDominant = 0;
        if(nums[0] >= nums[1]) countDominant++;
        if(nums[n-1] >= nums[n-2]) countDominant++;
        for(int i = 1;i<n-1;i++){
            if(nums[i] >= (float)(nums[i-1] + nums[i+1])/2){
                countDominant++;
            }
        }
        return countDominant;
    }
};