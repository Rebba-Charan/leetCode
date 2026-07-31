class Solution {
public:
    struct comparesecond {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        if(p1.second == p2.second) return p1.first<p2.first;
        return p1.second < p2.second; 
    }
};
    int minimumPushes(string word) {
        int n = word.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparesecond> q;
        vector<int> freq(26,0);
        for(char c : word)
        {
            freq[c - 'a']++;
        }
        for(int i= 0;i<26;i++)
        {
            if(freq[i]!= 0) q.push({i,freq[i]});
        }
        int index = 0;
        int ans = 0;
        while(!q.empty())
        {
            pair<int,int> temp = q.top();
            q.pop();
            ans = ans + ((index/8 + 1)*(temp.second));
            index++;
        }
        return ans;
    }
};