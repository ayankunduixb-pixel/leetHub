// // Brute Force Approach
// class Solution {
// public:
//     void solve(int idx,vector<int>& temp, int n,vector<int>& nums,set<vector<int>>& result){
//         if(idx >= n){
//             result.insert(temp);
//             return;
//         }
//         // Take
//         temp.push_back(nums[idx]);
//         solve(idx+1,temp,n,nums,result);
//         // Not Take
//         temp.pop_back();
//         solve(idx+1,temp,n,nums,result);

//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         set<vector<int>> result;
//         vector<int> temp;
//         solve(0,temp,n,nums,result);
//         vector<vector<int>> ans(result.begin(), result.end());
//         return ans;
//     }
// };

// // Optimal Approach

class Solution {
public:
    void solve(int idx,vector<int>& temp, int n,vector<int>& nums,vector<vector<int>>& result){
        result.push_back(temp);
        for(int i=idx;i<n;i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,temp,n,nums,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(0,temp,n,nums,result);
        return result;
    }
};