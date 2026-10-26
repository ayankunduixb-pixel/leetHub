// Brute-force: T.C: O(n* (klogk))
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int n = strs.size();
//         vector<vector<string>> result;
//         unordered_map<string,vector<string>> mpp;

//         for(int i = 0;i<n;i++){
//             string temp = strs[i];
//             sort(begin(temp),end(temp));
//             mpp[temp].push_back(strs[i]);
//         }

//         for(auto it : mpp){
//             result.push_back(it.second);
//         }
//         return result;
//     }
// };

// Optimal approach : T.C: O(n*k)
class Solution {
public:
    string generate(string &word){ // sorted anagram
        int arr[26] = {0};
        for(char &ch : word){
            arr[ch-'a']++;
        }
        string new_word = "";
        for(int i = 0;i<26;i++){
            int freq = arr[i];
            if(freq > 0){
                new_word += string(freq,i+'a');
            }
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mpp;

        for(int i = 0;i<n;i++){
            string word = strs[i];
            string new_word = generate(word);
            mpp[new_word].push_back(strs[i]);
        }

        for(auto it : mpp){
            result.push_back(it.second);
        }
        return result;
    }
};