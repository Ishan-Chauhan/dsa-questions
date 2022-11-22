class Solution {
public:
    vector<int> v;
    vector<vector<int>> dp;
    int util(int i, int n)
    {
        // cout<<1;
        if(i<0 || n<0) return 1e9;
        if(n==0) return 0;
        
        if(dp[i][n]!=-1) return dp[i][n];
        
        int take = 1 + util(i,n-v[i]);
        int not_take = util(i-1,n);
        
        dp[i][n] = min(take,not_take);
        // cout<<dp[i][n];
        return dp[i][n];
    }
    int numSquares(int n) {
        int x = int(sqrt(n));
        if(x*x==n) return 1;
        
        dp.resize(x,vector<int>(n+1,-1));
        
        for(int i=1;i<=x;i++)
        {
            v.push_back(i*i);
        }
        // cout<<v[x-1];
        int ans = util(x-1,n);
        return ans;
    }
};