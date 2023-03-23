class Solution {
public:
    int extra=0;
    int find(int i, vector<int>&p)
    {
        if(p[i]<0) return i;
        return find(p[i],p);
    }
    void unionn(int a, int b, vector<int>&p)
    {
        int p1 = find(a, p);
        int p2 = find(b, p);
        if(p1!=p2)
        {
            if(p[p1]<=p[p2])
            {
                p[p1]+=p[p2];
                p[p2]=p1;
            }
            else
            {
                p[p2]+=p[p1];
                p[p1]=p2;
            }
        }
        else extra++;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> p(n,-1);
        int m = connections.size();
        for(int i=0;i<m;i++)
        {
            unionn(connections[i][0], connections[i][1], p);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(p[i]<0) c++;
        }
        c--;
        if(c<=extra) return c;
        return -1;
    }
};