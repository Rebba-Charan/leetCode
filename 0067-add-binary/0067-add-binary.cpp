class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(),m = b.size();
        int carry = 0;
        int i = n-1,j = m-1;
        string ans;
        while(i>=0 && j>=0)
        {
            int a_bit = (a[i] - '0');
            int b_bit = (b[j] - '0');
            ans = (to_string(a_bit^b_bit^carry)) + ans;
            carry = ((a_bit&b_bit) | (b_bit&carry) | (carry&a_bit) );
            i--;
            j--;
        }
        while(i>=0)
        {
            int a_bit = (a[i]-'0');
            ans = to_string(a_bit^carry) + ans;
            carry = a_bit&carry;
            i--;
        }
        while(j>=0)
        {
            int b_bit = (b[j]-'0');
            ans = to_string(b_bit^carry) + ans;
            carry = b_bit&carry;
            j--;
        }
        if(carry == 1)
        {
            ans = to_string(carry)   + ans;
        }
        return ans;
    }
};