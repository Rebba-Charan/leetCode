class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        long long ans;
        string x;
        long long sum = 0;
        string s = to_string(n);
        for(char c : s)
        {
            if(c != '0')
            {
                x = x + c;
                sum+=(c-'0');
            }
        }
        long long val = stoi(x);
        ans = val*sum;
        return ans;
    }
};