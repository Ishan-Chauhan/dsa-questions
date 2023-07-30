class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        int n=grid.size(), m=grid[0].size();
        int fresh=0;
        
        queue<vector<int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        
        if(fresh==0) return time;
        
        vector<int> dir{0,1,0,-1,0};
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int x=q.front()[0];
                int y=q.front()[1];
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int newx = x+dir[i];
                    int newy = y+dir[i+1];
                    
                    
                    if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1)
                    {
                        grid[newx][newy]=2;
                        fresh--;
                        q.push({newx, newy});
                    }
                }
            }
            
            time++;
            if(fresh==0) return time;
        }
        
        return -1;
    }
};