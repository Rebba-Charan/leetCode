class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int ans = 0;
        int n = s.size();
        int i = 0;
        while(i<n){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(i == n-1){
                    if(!st.empty()){
                        ans+=1;
                        st.pop();
                    }
                    else{
                        ans+=2;
                    }
                    break;
                }
                if(s[i] == s[i+1]){
                    if(!st.empty()){
                        st.pop();
                    }
                    else{
                        ans+=1;
                    }
                    i+=1;
                }
                else{
                    if(!st.empty()){
                        ans+=1;
                        st.pop();
                    }
                    else{
                        ans+=2;
                    }
                }
            }
            i++;
        }
        while(!st.empty()){
            ans+=2;
            st.pop();
        }
        return ans;
    }
};