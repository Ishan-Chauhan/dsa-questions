class Solution {
public:
    int sol(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& v)
    {
        if(i>=n || j>=m)
        {
            return 1e9;
        }
        if(v[i][j]!=-1) return v[i][j];
        if(i==n-1 && j==m-1)
        {
            return v[i][j]=grid[i][j];
        }
        
        int r = sol(grid,i,j+1,n,m,v);
        int d = sol(grid,i+1,j,n,m,v);
            
        return v[i][j]=grid[i][j] + min(r,d);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> v(n,vector<int>(m,-1));
        
        int ans = sol(grid,0,0,n,m,v);
        
        return ans;
    }
};