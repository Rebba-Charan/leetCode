class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n == 1) return s[0] == goal[0];
        string dummy = s+s;
        for(int i = 0;i<n;i++)
        {
            if(goal == dummy.substr(i,n)) return 1;
        }
        return  0;
    }
};