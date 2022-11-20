class Solution {
public:
    int sol(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& v)
    {
        if(i<0 || j<0)
        {
            return 1e9;
        }
        if(v[i][j]!=-1) return v[i][j];
        if(i==0 && j==0)
        {
            return v[i][j]=grid[i][j];
        }
        
        int r = sol(grid,i,j-1,v);
        int d = sol(grid,i-1,j,v);
            
        return v[i][j]=grid[i][j] + min(r,d);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> v(n,vector<int>(m,-1));
        
        int ans = sol(grid,n-1,m-1,v);
        
        return ans;
    }
};