class Solution {
public:
    long long fuel = 0;
    long long dfs(int node, int prev, vector<vector<int>>& adj, int seats)
    {
        long long r = 1;
        for(auto& it: adj[node])
        {
            if(it!=prev)
            {
                r += dfs(it, node, adj, seats);
            }
        }
        if(node!=0) fuel += ceil((double)r/seats);
        
        return r;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size(), nodes=0;
        
        for(int i=0;i<n;i++)
        {
            nodes = max(nodes, max(roads[i][0], roads[i][1]));
        }
        vector<vector<int>> adj(nodes+1);
        for(int i=0;i<n;i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        long long ans = dfs(0, -1, adj, seats);
        
        return fuel;;
    }
};