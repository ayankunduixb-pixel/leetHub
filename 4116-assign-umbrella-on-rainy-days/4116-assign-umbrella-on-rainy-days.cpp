class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string> ans;
        int a = 0,b = 0;
        int n = rain.size();
        for(int i = 0;i<n;i++){
            int aneed = 0,bneed = 0;
            if(i+1<n && rain[i] == rain[i+1] && rain[i] == 1){
                aneed = 1;
            }
            if(rain[i] == 1){
                bneed = 1;
            }
            if(aneed == 0 && bneed == 0){
                ans.push_back("None");
            }
            else if(aneed == 1 && bneed == 1){
                if(a <= b){
                    a++;
                    ans.push_back("Alice");
                }
                else{
                    b++;
                    ans.push_back("Bob");
                }
            }
            else if(aneed == 1){
                a++;
                ans.push_back("Alice");
            }
            else{
                b++;
                ans.push_back("Bob");
            }
        }
        return ans;
    }
};