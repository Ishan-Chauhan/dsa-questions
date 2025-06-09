class Solution {
public:
    int numDecodings(string s) {
        // return 0;
        if(s[0]=='0') return 0;
        int n=s.size();
        if(n==1) return 1;

        vector<int> dp(n, 0);
        dp[0] = 1;
        int x;
        x = (s[0]-'0')*10 + (s[1]-'0');

        if(x>=1 && x<=26) 
        {
            if(x%10==0) dp[1]=1;
            else dp[1] = 2;
        }
        else if(x%10==0) return 0;
        else dp[1] = 1;

        for(int i=2;i<n;i++)
        {
            if(s[i-1]=='0') 
            {
                if(s[i]=='0') return 0;
                dp[i] = dp[i-1];
                // cout<<dp[i]<<" ";
                continue;
            }

            x = (s[i-1]-'0')*10 + (s[i]-'0');

            if(x>=1 && x<=26) 
            {
                if(x%10==0) dp[i] = dp[i-2];
                else dp[i] = dp[i-1] + dp[i-2];
            }
            else if(x%10==0) return 0;
            else dp[i] = dp[i-1];

            // cout<<dp[i]<<" ";
        }
        return dp[n-1];
    }
};