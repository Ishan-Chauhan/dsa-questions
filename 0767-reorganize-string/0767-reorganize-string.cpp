class Solution {
public:
    string reorganizeString(string& s) {
        int n=s.size(), maxoccur=0, occur=0;
        vector<int> m(26, 0);
        
        for(int i=0;i<n;i++)
        {
            m[s[i]-'a']++;
            if(m[s[i]-'a']>ceil(n/2.0)) return "";
            
            if(m[s[i]-'a']>occur)
            {
                occur=m[s[i]-'a'];
                maxoccur=s[i]-'a';
            }
        }
        string ans(n, '.');
        int i=0;
        
        while(m[maxoccur]--)
        {
            ans[i] = ('a' + maxoccur);
            i+=2;
        }
        
        for(int j=0;j<26;j++)
        {
            while(m[j]>0)
            {
                if(i>=n) i=1;
                ans[i] = ('a' + j);
                i+=2;
                m[j]--;
            }
        }
        
        return ans;
    }
};