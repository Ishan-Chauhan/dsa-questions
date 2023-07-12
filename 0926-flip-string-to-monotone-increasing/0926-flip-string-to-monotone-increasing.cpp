class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int ans=0;
        int ones=0;
        
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='1') 
            {
                ones++;
            }
            else
            {
                ans = min(ones, 1+ans);
            }
        }
        return ans;
    }
};