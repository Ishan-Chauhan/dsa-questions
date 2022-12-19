class Solution {
public:
    int find(int a, vector<int>& parent)
    {
        if(parent[a]<0) return a;
        return find(parent[a],parent);
    }
    void unioon(int a, int b, vector<int>& parent)
    {
        int p1=find(a,parent);
        int p2=find(b,parent);
        
        if(p1!=p2)
        {
            if(parent[p1]<=parent[p2])
            {
                parent[p1]+=parent[p2];
                parent[p2]=p1;
            }
            else
            {
                parent[p2]+=parent[p1];
                parent[p1]=p2;
            }
            // return false;
        }
        // return true;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();
        
        vector<int> parent(n,-1);
        
        for(int i=0;i<m;i++)
        {
            unioon(edges[i][0],edges[i][1],parent);
        }
        return find(source,parent)==find(destination,parent);
    }
};