class Solution {
public:
    string Approach1(int num, int sum){
        if(sum < 1 || sum > num * 9) return "";
        string ans = "";
        while(sum > 0){
            ans.push_back(min(sum,9) + '0');
            sum-=9;
        }
        if (ans.length() < num) {
            ans.append(num - ans.length(), '0');
        }
        return ans;
    }
    string Approach2(int num, int sum){
        if(sum < 1 || sum > num*9){
            return "";
        }

        int nines = sum/9;
        int remainder = sum % 9;
        
        // Added number of 9's first 
        string result(nines,'9'); // O(num)

        if(remainder > 0){
            result.push_back(remainder + '0'); //O(1)
        }

        result.append(num-result.length() , '0');

        return result;
    }
    string maxSumOfSquares(int num, int sum) {
        return Approach1(num,sum);
        // return Approach2(num,sum);
    }
};