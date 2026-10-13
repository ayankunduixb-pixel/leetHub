class Solution {
private:
    long long Approach1(vector<int>& nums) {
        // Two pointer Approach
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        long long ans = 0;
        while(i<j){
            ans += (nums[j]*nums[j])-(nums[i]*nums[i]);
            i++;
            j--;
        }
        if(i==j) ans += (nums[i]*nums[i]);
        return ans;
    }
    long long Approach2(vector<int>& nums) {
        // Sorting
        int n = nums.size();
        for(int i = 0;i<n;i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        long long smallerHalf = accumulate(nums.begin(),nums.begin()+n/2 , 0LL);
        long long largerHalf = accumulate(nums.begin()+n/2,nums.end(),0LL);
        return largerHalf - smallerHalf;
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // return Approach1(nums); // O(nlogn)
        return Approach2(nums); // O(nlogn)

    }
};