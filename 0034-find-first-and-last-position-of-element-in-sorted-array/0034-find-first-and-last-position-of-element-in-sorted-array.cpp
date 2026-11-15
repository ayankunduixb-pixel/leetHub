class Solution {
private:
    vector<int> brute_force(vector<int>& nums, int target){
        int n=nums.size();
        int first_position=-1;
        int last_position=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                if(first_position==-1){
                    first_position=i;
                }
                last_position=i;
            }
        }
        return {first_position,last_position};
    }
    int first_occurence(vector<int>& nums, int target){
        int n=nums.size();
        int first_position=-1;
        int low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first_position=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first_position;
    }

    int last_occurence(vector<int>& nums, int target){
        int n=nums.size();
        int last_position=-1;
        int low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last_position=mid;
                low=mid+1;
            }
            else if (nums[mid]>target) {
                high = mid - 1;
            }
            else{
                low=mid+1;
            }
        }
        return last_position;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //return brute_force(nums,target);
        return {first_occurence(nums,target),last_occurence(nums,target)};
    }
};