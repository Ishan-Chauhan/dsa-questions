class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        int m = flights.size();
        vector<int> mini(n,INT_MAX);
        for(int i=0;i<m;i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        int stop=0;
        int size;
        while(!q.empty() && stop<=k)
        {
            size = q.size();
            while(size--)
            {
                auto [node, price] = q.front();
                q.pop();
                
                for(auto& [neighbour, cost]: adj[node])
                {
                    if(price + cost < mini[neighbour])
                    {
                        mini[neighbour] = price + cost;
                        q.push({neighbour,mini[neighbour]});
                    }
                }
            }
            stop++;
        }
        return (mini[dst]==INT_MAX)?-1:mini[dst];
    }
};