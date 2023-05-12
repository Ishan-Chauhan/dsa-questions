class Solution {
public:
    long long sol(vector<vector<int>>& q, int i, int n, vector<long long>& dp)
    {
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        long long take = q[i][0] + sol(q, i+q[i][1]+1, n, dp);
        long long not_take = sol(q, i+1, n, dp);
        
        dp[i] = max(take, not_take);
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+1, -1);
        return sol(q, 0, n, dp);
    }
};