class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=INT_MIN;
        for(char ch:s){
            if(ch=='('){
                count++;
            }
            else if(ch==')'){
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};