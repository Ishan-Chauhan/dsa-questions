class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(),i,j;
        vector<int> col(n,0),row(n,0);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                row[i] = max(row[i],grid[i][j]);
                col[j] = max(col[j],grid[i][j]);
            }
        }
        
        int ans = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                ans += min(row[i],col[j])-grid[i][j];
            }
        }
        return ans;
    }
};