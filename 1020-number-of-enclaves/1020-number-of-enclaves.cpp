class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>> q;
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1) 
            {
                // grid[i][0]=2;
                q.push({i,0});
            }
            if(grid[i][m-1]==1) 
            {
                // grid[i][m-1]=0;
                q.push({i,m-1});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1) 
            {
                // grid[0][i]=2;
                q.push({0,i});
            }
            if(grid[n-1][i]==1) 
            {
                // grid[n-1][i]=2;
                q.push({n-1,i});
            }
        }
        
        
        
        while(!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
            {
                if(grid[x][y]==1) grid[x][y]=2;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};