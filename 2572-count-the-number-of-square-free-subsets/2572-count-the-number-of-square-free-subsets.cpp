class Solution {
private:
    vector<int> prime{2,3,5,7,11,13,17,19,23,29};
    int mod=1000000007;
    
    int primemask(int num)
    {
        int mask=0;
        int c;
        
        for(int i=0;i<10;i++)
        {
            c=0;
            while(num%prime[i]==0)
            {
                c++;
                num/=prime[i];
            }
            if(c>1) return -1;
            
            if(c==1) mask |= (1<<(i+1));
        }
        return mask;
    }
    
public:
    int sol(int i, int mask, int n, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i==n) return 1;
        
        if(dp[i][mask]!=-1) return dp[i][mask];
        
        int nummask = primemask(nums[i]);
        int ans = sol(i+1, mask, n, nums, dp);
        
        if((mask&nummask) == 0)
        {
            ans = (ans%mod + (sol(i+1, mask|nummask, n, nums, dp)%mod) )%mod;
        }
        
        return dp[i][mask] = ans;
    }
    int squareFreeSubsets(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n, vector<int>(1<<11,-1));
        
        return (sol(0, 1, n, nums, dp)-1+mod)%mod;
    }
};