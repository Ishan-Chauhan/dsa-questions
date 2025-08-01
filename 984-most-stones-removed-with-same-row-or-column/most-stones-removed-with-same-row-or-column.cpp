class Solution {
public:
    int find(int a, vector<int>& p)
    {
        if(p[a]<0) return a;
        return p[a] = find(p[a], p);
    }
    void unionn(int a, int b, vector<int>& p)
    {
        int x=find(a, p);
        int y=find(b, p);

        if(x!=y)
        {
            if(p[x]<=p[y])
            {
                p[x]+=p[y];
                p[y]=x;
                p[b]=x;
            }
            else
            {
                p[y]+=p[x];
                p[x]=y;
                p[a]=y;
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> v(n, -1);

        for(int i=1;i<n;i++)
        {
            int x=stones[i][0];
            int y=stones[i][1];
            for(int j=0;j<i;j++)
            {
                int nx=stones[j][0];
                int ny=stones[j][1];

                if(x==nx || y==ny)
                {
                    unionn(i, j, v);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]<0) ans += -(v[i]+1);
        }

        return ans;
    }
};