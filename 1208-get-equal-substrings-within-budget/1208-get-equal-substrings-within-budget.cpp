class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int> v(n, 0);
        
        for(int i=0;i<n;i++) v[i]=abs(s[i]-t[i]);
        
        int i=0,j=0;
        int sum=0;
        int ans=0;
        
        while(j!=n)
        {
            sum+=v[j];
            
            while(sum>maxCost)
            {
                sum-=v[i];
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }
};