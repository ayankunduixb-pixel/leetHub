class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int i = 0;
        int n = s1.size();
        vector<vector<string>> ans;
        while(i < n){
            if(s1[i] == s2[i]){
                i++;
                continue;
            }
            int l = i;
            while(i<n && s1[i] != s2[i]){
                i++;
            }
            // string sub1 = s1.substr(l,i-l);
            // string sub2 = s2.substr(l,i-l);
            ans.push_back({s1.substr(l,i-l),s2.substr(l,i-l)});
        }
        return ans;
    }
};