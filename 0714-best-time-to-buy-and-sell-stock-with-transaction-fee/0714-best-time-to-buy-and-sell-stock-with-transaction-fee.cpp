class Solution {
public:
    int sol(vector<int>& prices, int fee, int i, int b, int n, vector<vector<int>>& dp)
    {
        if(i==n) return  0;
        
        if(dp[i][b]!=-1) return dp[i][b];
        if(b==0)
        {
            dp[i][b] = max(sol(prices, fee, i+1, 0, n, dp), sol(prices, fee, i+1, 1, n, dp)-fee+prices[i]);
        }
        else
        {
            dp[i][b] = max(sol(prices, fee, i+1, 1, n, dp), sol(prices, fee, i+1, 0, n, dp)-prices[i]);
        }
        return dp[i][b];
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return sol(prices, fee, 0, 1, prices.size(), dp);
    }
};