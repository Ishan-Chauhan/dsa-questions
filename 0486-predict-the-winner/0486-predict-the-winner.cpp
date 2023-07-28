class Solution {
public:
    int sol(vector<int>& nums, int i, int j, vector<vector<int>>& dp)
    {
        if(i==j) return nums[i];
        
        if(dp[i][j]!=1e8) return dp[i][j];
        
        int start = nums[i] - sol(nums, i+1, j, dp);
        int end = nums[j] - sol(nums, i, j-1, dp);
        
        return dp[i][j] = max(start, end);
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        
        int n=nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 1e8));
        int ans = sol(nums,0,n-1,dp);
        
        return ans>=0;
    }
};