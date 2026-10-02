class Solution {
public:
    void solve(string temp,int open_count,int close_count,int n,int count,vector<string>& ans){
        if(count<0) return;
        if(open_count>n || close_count>n) return;
        if(open_count == n && close_count == n && count == 0){
            ans.push_back(temp);
            return;
        }
        solve(temp + '(',open_count+ 1,close_count,n,count+1,ans);
        solve(temp + ')',open_count,close_count+1,n,count-1,ans);

    }
    vector<string> generateParenthesis(int n) {
        // if(n == 1) return "()";
        string temp = "";
        vector<string> ans;
        solve(temp,0,0,n,0,ans);
        return ans;
    }
};