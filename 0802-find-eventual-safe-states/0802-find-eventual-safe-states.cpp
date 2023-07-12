class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph1) {
        int n = graph1.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n,0), res;
        
        for(int i=0;i<n;i++)
        {
            for(auto it: graph1[i])
            {
                graph[it].push_back(i);
                // cout<<it<<" "<<i<<endl;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(auto node: graph[i]) indegree[node]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++) 
        {
            if(indegree[i]==0) 
            {
                q.push(i);
                res.push_back(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto x: graph[node])
            {
                indegree[x]--;
                if(indegree[x]==0) 
                {
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};