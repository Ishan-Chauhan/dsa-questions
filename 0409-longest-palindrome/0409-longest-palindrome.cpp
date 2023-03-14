class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        map<char,int> m;
        
        int ans=0,f=0;
        
        for(int i=0;i<n;i++) m[s[i]]++;
        
        for(auto& it: m)
        {
            if(it.second%2==0) ans+=it.second;
            else
            {
                ans += it.second-1;
                f=1;
            }
        }
        
        if(f) return ans+1;
        
        return ans;
    }
};