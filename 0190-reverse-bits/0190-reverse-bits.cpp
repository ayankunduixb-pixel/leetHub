class Solution {
public:
    // string decimalToBinary(int decimal) {
    //     if (decimal == 0) return "0";

    //     string binary = "";

    //     while (decimal > 0) {
    //         binary += (decimal % 2) + '0';
    //         decimal /= 2;
    //     }

    //     reverse(binary.begin(), binary.end());

    //     return binary;
    // }
    int reverseBits(int n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }

        return ans;
    }
};