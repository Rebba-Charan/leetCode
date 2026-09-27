class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<int> st;
        int n = s.size();
        int num = 0;
        for(int i = 0 ;i<n;i++){
            if(s[i] == '(') {
                st.push(num);
                continue;
            }
            if(s[i] == ')'){
                int start = st.top();
                st.pop();
                reverse(ans.begin()+start,ans.end());
                continue;
            }
            ans+=s[i];
            num++;
        }
        return ans;
    }
};