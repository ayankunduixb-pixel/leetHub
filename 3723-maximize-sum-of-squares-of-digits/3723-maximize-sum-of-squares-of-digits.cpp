class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // if(sum < 1 || sum > num*9){
        //     return "";
        // }

        // int nines = sum/9;
        // int remainder = sum % 9;
        
        // // Added number of 9's first 
        // string result(nines,'9'); // O(nines)

        // if(remainder > 0){
        //     result.push_back(remainder + '0'); //O(1)
        // }

        // result.append(num-result.length() , '0');

        // return result;

        if(sum < 1 || sum > num * 9) return "";
        string ans = "";
        while(sum > 9){
            ans.push_back(9 + '0');
            sum-=9;
        }
        if(sum > 0){
            ans.push_back(sum + '0');
        }
        if (ans.length() < num) {
            ans.append(num - ans.length(), '0');
        }
        return ans;
    }
};