class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            int bitwiseAND = nums[i];
            int minValue = nums[i];
            for(int j = i;j<n;j++){
                bitwiseAND &= nums[j];
                minValue = min(minValue,nums[j]);

                if(bitwiseAND == minValue){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};