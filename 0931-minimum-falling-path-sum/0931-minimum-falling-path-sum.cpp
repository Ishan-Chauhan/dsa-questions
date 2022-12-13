class Solution {
public:
    int ans=INT_MAX;
    int sol(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(j<0 || j==n) return 1e9;
        if(i==n-1)
        {
            // temp += matrix[i][j];
            return dp[i][j] = matrix[i][j];
        }
        // temp += matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int l = matrix[i][j] + sol(matrix, i+1, j-1, n,dp);
        int d = matrix[i][j] + sol(matrix, i+1, j, n, dp);
        int r = matrix[i][j] + sol(matrix, i+1, j+1, n, dp);
        
        return dp[i][j] = min(l,min(d,r));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            ans = min(ans,sol(matrix, 0, i, n, dp));
        }
        return ans;
    }
};