class Solution {
public:
    long long countValidSubstrings(string s) {
        long long count = 0;
        int i = 0;
        for(int j = 0;j<s.length();j++){
            if(j >= 2 && s[j - 2] == 'a' && s[j - 1] == 'b' && s[j] == 'c'){
                i = j-1;
            }
            count += (j-i+1);
        }
        return count;
    }
};