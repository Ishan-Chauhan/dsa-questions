class Solution {
public:
    int sol(int i, int n, string& s, map<string, int>& mp, vector<int>& dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        string temp="";
        int ans=INT_MAX;
        
        for(int j=i;j<n;j++)
        {
            temp+=s[j];
            if(mp.find(temp)!=mp.end())
            {
                ans = min(ans, sol(j+1,n,s,mp,dp));
            }
            
            ans = min(ans, j-i+1+sol(j+1,n,s,mp,dp));
        }
        
        return dp[i] = ans;
    }
    
    int minExtraChar(string& s, vector<string>& dic) {
        map<string, int> mp;
        for(auto it: dic) mp[it]=1;
        
        int n=s.size();
        
        vector<int> dp(n, -1);
        
        return sol(0,n,s,mp, dp);
    }
};