class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int lastIndexA = -1;
        int firstIndexB = n;
        for(int i = 0;i<n;i++){
            if(s[i] == 'a'){
                lastIndexA = i;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(s[i] == 'b'){
                firstIndexB = i;
            }
        }
        return lastIndexA < firstIndexB;
    }
};