class Solution {
    int extra=0;
    int find(vector<int>& par, int a)
    {
        if(par[a]==-1) return a;
        return par[a] = find(par, par[a]);
    }
    void unionn(int a, int b, vector<int>& par)
    {
        int x = find(par, a);
        int y = find(par, b);

        if(x!=y)
        {
            par[x]=y;
            par[a]=y;
        }
        else extra++;
    }
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        int c=con.size();

        if(c<n-1) return -1;

        vector<int> par(n, -1);

        for(int i=0;i<c;i++)
        {
            unionn(con[i][0], con[i][1], par);
        }

        int need=0;
        for(int i=0;i<n;i++)
        {
            if(par[i]==-1) need++;
        }

        return need-1;
    }
};