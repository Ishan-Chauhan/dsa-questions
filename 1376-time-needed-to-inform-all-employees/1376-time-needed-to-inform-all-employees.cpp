class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1) return 0;
        vector<vector<int>> adj(n, vector<int>(0));
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
            mp[i]=informTime[i];
        }
        vector<int> v(n,0);
        v[headID]=1;
        queue<vector<int>> q;
        q.push({headID, informTime[headID]});
        int node, time, ans=0;
        while(!q.empty())
        {
            node=q.front()[0];
            time=q.front()[1];
            q.pop();
            for(auto &it: adj[node])
            {
                ans=max(ans,time+mp[it]);
                q.push({it, time+mp[it]});
            }
        }
        return ans;
    }
};