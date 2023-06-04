class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& v)
    {
        cout<<node<<" ";
        if(v[node]==1) return;
        v[node]=1;
        for(auto& it: adj[node]) dfs(it, adj, v);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        int m=isConnected.size();
        vector<vector<int>> adj(n,vector<int>(0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> v(n,0);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                c++;
                dfs(i, adj, v);
            }
        }
        return c;
    }
};