class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<pair<int, int>> vis(n, pair<int, int>(INT_MAX, INT_MAX));

        int x = flights.size();

        for(int i=0;i<x;i++)
        {
            int sc=flights[i][0];
            int dt=flights[i][1];
            int cost=flights[i][2];

            adj[sc].push_back({dt, cost});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, -1, src});  //cost  stops   node

        while(!pq.empty())
        {
            int cost = pq.top()[0];
            int stops = pq.top()[1];
            int node = pq.top()[2];
            // cout<<node<<" ";
            pq.pop();

            if(stops<=k && node==dst) return cost;
            if(stops>k) continue;

            for(auto it: adj[node])
            {
                if(cost+it.second<=vis[it.first].first || stops+1<=vis[it.first].second)
                {
                    pq.push({cost+it.second, stops+1, it.first});
                    vis[it.first].first = cost+it.second;
                    vis[it.first].second = stops+1;
                }
            }
        }
        return -1;
    }
};