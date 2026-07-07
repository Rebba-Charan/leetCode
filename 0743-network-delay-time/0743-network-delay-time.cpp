class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       if(n==1) return 0;
       unordered_map<int,vector<pair<int,int>>> adj;
       for(vector<int>& p : times )
       {
            int u = p[0];
            int v = p[1];
            int t = p[2];
            adj[u].push_back({v,t});
       }
       vector<int> visited(n+1,0);
       visited[0] = -1;
       vector<int> distance(n+1,INT_MAX);
       distance[0] = -1;
    //    int max_time = INT_MIN;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
       visited[k] = 1;
       distance[k] = 0;
       que.push({0,k});
       while(!que.empty())
       {
        pair<int,int> dummy = que.top();
        que.pop();
        int u = dummy.second;
        int d = dummy.first;
        for(pair<int,int>& temp : adj[u])
        {
            int v = temp.first;
            int dis = temp.second;
            if((d+dis)< distance[v])
            {
                if(!visited[v]) visited[v] = 1;
                distance[v] = d+dis;
                // max_time = max(max_time,d+dis);
                que.push({(d+dis),v});
            }
        }
       }
       for(int val : visited)
       {
        if(val == 0) return -1;
       } 
       return *max_element(distance.begin(),distance.end());
    }
};