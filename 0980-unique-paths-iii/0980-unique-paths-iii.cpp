class Solution {
public:
    int sol(vector<vector<int>>& grid,int x,int y,int n,int m,int c,int visit)
    {
        if(x<0 || y<0 || x==n || y==m || grid[x][y]==3|| grid[x][y]==-1) return 0;
        
        
        if(grid[x][y]==2)
        {
            if(visit==c+1) return 1;
            return 0;
        }
        grid[x][y]=3;
        
        int up = sol(grid,x-1,y,n,m,c,visit+1);
        int dn = sol(grid,x+1,y,n,m,c,visit+1);
        int l = sol(grid,x,y-1,n,m,c,visit+1);
        int r = sol(grid,x,y+1,n,m,c,visit+1);
        
        grid[x][y]=0;
        
        return up+dn+l+r;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c=0,x,y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) c++;
                else if(grid[i][j]==1)
                {
                    // grid[i][j]=3;
                    x=i;
                    y=j;
                }
            }
        }
        return sol(grid,x,y,n,m,c,0);
    }
};