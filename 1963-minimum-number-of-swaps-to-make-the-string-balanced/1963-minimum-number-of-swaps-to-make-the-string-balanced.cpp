class Solution {
private:
    int Approach1(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch == '['){
                st.push(ch);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        return (st.size()+1)/2;
    }
    int Approach2(string s) {
        int size = 0;
        for(char ch:s){
            if(ch == '['){
                size++;
            }
            else if(size > 0){
                size--;
            }
        }
        return (size+1)/2;
    }
public:
    int minSwaps(string s) {
        // return Approach1(s);
        return Approach2(s);
    }
};