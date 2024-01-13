class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> dp(n, 1), par(n,-1);
        int maxlen=1;
        int last=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    par[i] = j;
                    if(dp[i]>maxlen)
                    {
                        maxlen=dp[i];
                        last=i;
                    }
                }
            }
        }
        // if(maxlen<=1) return {};
        
        vector<int> res(maxlen);
        int j=maxlen-1;
        
        while(j+1)
        {
            // cout<<last<<endl;
            res[j--]=nums[last];
            last=par[last];
        }
        
        return res;
    }
};