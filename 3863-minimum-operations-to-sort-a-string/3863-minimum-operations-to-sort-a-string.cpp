// class Solution {
// public:
//     bool isSorted(string s){
//         for(int i = 1;i<s.length();i++){
//             if(s[i-1] > s[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int minOperations(string s) {
//         if(isSorted(s)) return 0; // When the string is already sorted
//         int n = s.length();

//         if(n == 2) return -1; // When the string is not sorted and the length is 2

//         vector<int> freq(26,0);
//         char mini = 'z';
//         char maxi = 'a';

//         for(char ch : s){
//             mini = min(mini,ch);
//             maxi = max(maxi,ch);
//             freq[ch-'a']++; // we also calculate the freq in the same loop 
//         }

//         if(s[0] == mini || s[n-1] == maxi) return 1; // when the minimum character at the first index 
//         // and maimum character at the last index

//         if(s[0] == maxi && s[n-1] == mini){
//             if(freq[maxi - 'a'] == 1 && freq[mini - 'a'] == 1) return 3; // Wrost case
//             else return 2;
//         }

//         return 2; // if none of the condition returns the value simply answer will be 2
//     }
// };

// More cleaner version

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(is_sorted(begin(s), end(s)))
            return 0;
        
        if(n == 2) {
            return -1;
        }

        char min_char = *min_element(begin(s), end(s));
        char max_char = *max_element(begin(s), end(s));

        if(s[0] == min_char || s[n-1] == max_char)
            return 1;

        char max_mid = *max_element(begin(s)+1, end(s)-1);
        char min_mid = *min_element(begin(s)+1, end(s)-1);

        if(s[0] > max_mid && s[n-1] < min_mid) {
            return 3;
        }

        return 2;
    }
};