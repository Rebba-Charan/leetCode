class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        int n = s.size();
        unordered_set<char> set;
        for(char c : s) set.insert(c);
        if(set.size() == 1) return 0;
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = i;j<n;j++){
                if(s[j] == '(') count+=1;
                else count-=1;
                if(count <0) break;
                if(count == 0) maxlen = max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};