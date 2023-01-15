class Solution {
public:
    vector<int> parent;
    int find(int p)
    {
        if(parent[p]<0) return p;
        return find(parent[p]);
    }
    void unionn(int a, int b, vector<int>& vals)
    {
        int p1 = find(a);
        int p2 = find(b);
        
        if(p1!=p2)
        {
            if(vals[p1]<=vals[p2])
            {
                parent[p2]=p1;
            }
            else
            {
                parent[p1]=p2;
            }
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), ans=0;
        parent.resize(n,-1);
        vector<vector<int>> adj(n,vector<int>(0));
        int len = edges.size();
        for(int i=0;i<len;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            m[vals[i]].push_back(i);
        }
        
        for(auto& v:m)
        {
            for(int i=0;i<v.second.size();i++)
            {
                int node = v.second[i];
                for(auto& it: adj[node])
                {
                    if(vals[node]>=vals[it]) unionn(node,it,vals);
                }
            }
            
            map<int,int> mp;
            int c=0;
            for(int i=0;i<v.second.size();i++)
            {
                mp[find(v.second[i])]++;
            }
            for(auto ishan: mp)
            {
                c += ishan.second*(ishan.second+1)/2;
            }
            ans+=c;
        }
        return ans;
    }
};