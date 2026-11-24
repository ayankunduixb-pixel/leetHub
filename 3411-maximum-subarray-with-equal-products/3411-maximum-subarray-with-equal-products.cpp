class Solution {
public:
    long long gcd(long long a,long long b){
        while(b != 0){
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long lcm (long long a,long long b){
        return ((a*b) / gcd(a,b));
    }
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long double product = 0.0;
            long long gcdd = nums[i];
            long long lcmm = nums[i];
            for(int j = i;j<n;j++){
                product += log(nums[j]);
                gcdd = gcd(gcdd,nums[j]);
                lcmm = lcm(lcmm,nums[j]);

                if(abs(product - (log(gcdd) + log(lcmm))) < 1e-9){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};