class Solution {
public:
    bool sol(int i, string s, map<string,bool>& mp, vector<int>& dp)
    {
        if(i==s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        
        bool ans=false;
        
        for(int j=i+1;j<=s.size();j++)
        {
            string pre = s.substr(i, j-i);
            if(mp.find(pre)!=mp.end()) 
            {
                ans |= sol(j, s, mp, dp);
                if(ans) return ans;
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string& s, vector<string>& wordDict) {
        map<string,bool> mp;
        for(auto it: wordDict) mp[it]=true;
        
        int n=s.size();
        vector<int> dp(n,-1);
        
        return sol(0, s, mp, dp);
    }
};