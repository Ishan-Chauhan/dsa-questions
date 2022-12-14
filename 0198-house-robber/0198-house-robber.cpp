class Solution {
public:
    int sol(vector<int>& nums, int i, int n, vector<int>& dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int take = nums[i] + sol(nums, i+2, n, dp);
        int not_take = sol(nums, i+1, n, dp);
        
        return dp[i] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = max(sol(nums, 0, n, dp),sol(nums, 1, n, dp));
        return ans;
    }
};