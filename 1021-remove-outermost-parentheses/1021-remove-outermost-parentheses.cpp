class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(st.empty() && s[i] == '('){
                st.push(i);
            }
            else if(st.size() == 1 && s[i] == ')'){
                st.pop();
            }
            else{
                ans+=s[i];
                if(s[i] == '('){
                    st.push(i);
                }
                else{
                    st.pop();
                }
            }
        }
        return ans;
    }
};