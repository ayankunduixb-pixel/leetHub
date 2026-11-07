class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t) return true;
        if(s.size() > t.size()) return false;
        int sp = 0;
        int tp = 0;

        while (sp < s.length() && tp < t.length()) {
            if (s[sp] == t[tp]) {
                sp++;
            }
            tp++;
        }

        return sp == s.length();
    }
};