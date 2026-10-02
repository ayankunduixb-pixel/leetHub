// Brute Force Solution
// class Solution {
// public:
//     bool isValid(string s){
//         int balance = 0;
//         for(char ch : s){
//             if(ch == '(') balance++;
//             else balance--;
//             if(balance<0){
//                 return false;
//             }
//         }
//         return balance == 0;
//     }
//     void generateAll(string curr, int n, vector<string>& result){
//         if(curr.length() == 2*n){
//             if(isValid(curr)){
//                 result.push_back(curr);
//             }
//             return;
//         }
//         generateAll(curr + '(',n,result);
//         generateAll(curr + ')',n,result);
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         generateAll("",n,result);
//         return result;
//     }
// };


// Optimal Solution
class Solution {
public:
    void backTrack(string curr,int open, int close,int n, vector<string>& res){
        if(curr.length() == 2*n){
            res.push_back(curr);
            return;
        }
        if(open<n)      backTrack(curr+'(',open+1,close,n,res);
        if(close<open)  backTrack(curr+')',open,close+1,n,res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backTrack("",0,0,n,result);
        return result;
    }
};