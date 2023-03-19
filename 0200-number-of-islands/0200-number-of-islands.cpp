class Solution {
public:
    void sol(vector<vector<char>>& v,int x,int y)
    {
        //cout<<x<<" "<<y<<endl;
        if(x==-1 || x==v.size() || y==-1 || y==v[0].size()) return;
        
        v[x][y]='2';
        
        if(x+1!=v.size() && v[x+1][y]=='1')
            sol(v,x+1,y);
        if(x-1!=-1 && v[x-1][y]=='1')
            sol(v,x-1,y);
        if(y+1!=v[0].size() && v[x][y+1]=='1')
            sol(v,x,y+1);
        if(y-1!=-1 && v[x][y-1]=='1')
            sol(v,x,y-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    sol(grid,i,j);
                    c++;
                }
            }
        }
        return c;
    }
};