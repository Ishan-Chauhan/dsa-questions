class Solution {
private:
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathvis, vector<int>& res)
    {
        vis[i]=1;
        pathvis[i]=1;
        
        // cout<<i<<endl;
        for(auto node: graph[i])
        {
            if(!vis[node])
            {
                if(dfs(node, graph, vis, pathvis, res)==true) return true;
            }
            else if(pathvis[node]==1)
            {
                return true;
            }
        }
        
        // cout<<i<<endl;
        res.push_back(i);
        pathvis[i]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0), pathvis(n,0), res;
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, graph, vis, pathvis, res);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};