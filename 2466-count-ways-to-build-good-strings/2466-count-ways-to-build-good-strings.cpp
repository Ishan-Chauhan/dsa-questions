class Solution {
public:
    int sol(int z, int o, int size, vector<int>& dp)
    {
        if(size<0) return 0;
        if(size==0) return 1;
        
        if(dp[size]!=-1) return dp[size];
        
        int zero = sol(z, o, size-z, dp);
        int one = sol(z, o, size-o, dp);
        
        return dp[size] = (zero+one)%1000000007;
    }
    int countGoodStrings(int l, int h, int z, int o) {
        vector<int> dp(h+1,-1);
        int mod=1000000007, ans=0;
        for(int i=l;i<=h;i++)
        {
            ans = (ans + sol(z, o, i, dp)%mod)%mod;
        }
        return ans;
    }
};