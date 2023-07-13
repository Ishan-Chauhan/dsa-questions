class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        
        int n=pre.size();
        vector<int> adj[num];
        
        for(int i=0;i<n;i++)
            {
            adj[pre[i][1]].push_back(pre[i][0]);
            }
        vector<int> indegree(num,0);
        vector<int> top;
        
        for(int i=0;i<num;i++)
            {
            for(auto it: adj[i])
                {
                indegree[it]++;
                }
            }
        // cout<<1;
        queue<int> q;
        for(int i=0;i<num;i++)
            {
            if(indegree[i]==0) q.push(i);
            }
        
        
        while(!q.empty())
            {
            int node = q.front();
            q.pop();
            top.push_back(node);
            for(auto it: adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0) 
                        {
                        q.push(it);
                        }
                }
            }
        if(top.size()==num) return top;
        return {};
    }
};