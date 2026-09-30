class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int prev = 0;
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            if(seq[i] == '('){
                if(st.empty()){
                    st.push(prev);
                    ans[i] = prev;
                    prev = 1 - prev;
                }
                else {
                    int value ;
                    if(st.top() == 0) value = 1;
                    else if(st.top() == 1) value = 0;
                    ans[i] = value;
                    st.push(value);
                }
            }
            else if(seq[i] == ')'){
                ans[i] = st.top();
                st.pop();
            }
        }
        return ans;
    }
};