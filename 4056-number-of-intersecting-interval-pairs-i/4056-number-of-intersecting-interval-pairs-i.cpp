class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int minv = max(intervals[i][0],intervals[j][0]);
                int maxv = min(intervals[i][1],intervals[j][1]);
                if(minv <= maxv){
                    ans++;
                }
            }
        }
        return ans;
    }
};