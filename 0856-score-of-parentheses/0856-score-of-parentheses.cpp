class Solution {
private:
    int Approach1(string s) {
        int n = s.length();
        stack<int> st;
        int score = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }
            else{ // for ')'
                if(s[i-1] == '('){ // for simple '()'
                    score = st.top() + 1;
                }
                else{ // for ')' nested
                    score = st.top() + (2*score);
                }
                st.pop();
            }
        }
        return score;
    }
    int Approach2(string s) {
        int depth = 0;
        int score = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '('){
                depth++;
            }
            else{
                depth--;
                if(s[i-1] == '('){
                    score += (1<<depth);
                }
            }
        }
        return score;
    }
public:
    int scoreOfParentheses(string s) {
        // return Approach1(s);
        return Approach2(s);
    }
};