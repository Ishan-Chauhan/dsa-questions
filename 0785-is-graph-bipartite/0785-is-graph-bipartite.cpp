class Solution {
public:
    int par(int p,vector<int>& parent)
    {
        if(parent[p]<0) return p;
        return par(parent[p],parent);
    }
    void merge(int a,int b,vector<int>& parent)
    {
        // if(a==b) return;
        int x=par(a,parent);
        int y=par(b,parent);
        if(x==y) return;
        if(x<y)
        {
            parent[x]+=parent[y];
            parent[y]=x;
        }
        else
        {
            parent[y]+=parent[x];
            parent[x]=y;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++)
        {
            int m=graph[i].size();
            for(int j=0;j<m;j++)
            {
                if(par(i,parent)==par(graph[i][j],parent)) return false;
                merge(graph[i][0],graph[i][j],parent);
            }
            //cout<<endl;
        }
        return true;
    }
};