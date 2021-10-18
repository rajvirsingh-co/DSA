// Question link :  https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
// Level : medium

class Solution {
    vector<int> vec[100001];
    int dist[100001];
    bool visited[100001];
    int n;
    
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        n = patience.size();
        for(vector<int> ed : edges)
        {
            int x = ed[0], y = ed[1];
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        
        BFS();
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            int currTime = 2*dist[i];
            int finalCall = (currTime / patience[i]) * patience[i];
            
            if(finalCall == currTime)
                finalCall = max(finalCall-patience[i], 0);
            
            ans = max(ans, finalCall+currTime);
        }
        return ans+1;
    }
    
    void BFS() {
        
        visited[0] = true;
        dist[0] = 0;
        queue<int> qu;
        qu.push(0);
        
        while(!qu.empty()) {
            int x = qu.front();
            qu.pop();
            
            for(int a : vec[x])
            {
                if(!visited[a])
                {
                    dist[a] = dist[x]+1;
                    visited[a] = true;
                    qu.push(a);
                }
            }
        }
        
    }
};
