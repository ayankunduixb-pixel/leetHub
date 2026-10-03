class Solution {
public:
    int Approach1(string s){
        int n = s.length();
        int open = 0;
        int close = 0;

        int result = 0;

        // Left to right
        for(int i = 0; i < n; i++){
            if(s[i] == '(') open++;
            else close++;

            if(open == close){
                result = max(result,open+close);
            }
            else if(close>open){
                open = close = 0;
            }
        }

        open = 0;
        close = 0;

        // Right to left

        for(int i = n-1; i>=0; i--){
            if(s[i] == '(') open++;
            else close++;

            if(open == close){
                result = max(result,open+close);
            }
            else if(open > close){
                open = close = 0;
            }
        }
        return result;
    }
    int Approach2(string s){
        stack<int> st;
        st.push(-1);
        int maxLen = 0;

        for(int i = 0; i < s.length();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxLen = max(maxLen,i-st.top());
                }
            }
        }
        return maxLen;
    }

    int longestValidParentheses(string s) {
        // return Approach1(s);
        return Approach2(s);
    }
};
