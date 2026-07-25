class Solution {    
public:
    int M = 1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
    ll xora= 0,xorb = 0;
    for(ll i = 49;i>=n;i--)
    {
        bool a_bit = (a >> i) & 1 > 0; //Finding the ith bit of a
        bool b_bit = (b >> i) & 1 > 0; //Finding the ith bit of b
        if(a_bit)
        {
            xora = xora ^ (1ll<<i);
        }
        if(b_bit)
        {
            xorb = xorb ^ (1ll<<i);
        }  
    }
    for(ll i = n-1;i>=0;i--)
    {
        bool a_bit = (a >> i) & 1 > 0; //Finding the ith bit of a
        bool b_bit = (b >> i) & 1 > 0; //Finding the ith bit of b
        if(a_bit == b_bit)
        {
            xora = xora ^ (1ll<<i);
            xorb = xorb ^ (1ll<<i);
            continue;
        }
        if(xora> xorb)
        {
            xorb = xorb ^ (1ll<<i);
        }
        else
        {
            xora = xora ^ (1ll<<i);

        }
    }
    xora = xora%M;
    xorb = xorb%M;
    return (xora*xorb)%M;   
    }
};