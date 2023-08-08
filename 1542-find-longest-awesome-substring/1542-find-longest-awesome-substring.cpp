class Solution {
public:
    int longestAwesome(string& s) {
        int n=s.size();
        int mask=0;
        int len=0;
        vector<int> m(1024, -2);
        m[0]=-1;
        
        for(int i=0;i<n;i++)
        {
            mask ^= (1<<(s[i]-'0'));
            
            if(m[mask]==-2) m[mask] = i;
            len = max(len, i-m[mask]);
            
            for(int j=0;j<10;j++)
            {
                int newmask = mask^(1<<j);
                if(m[newmask]!=-2) len = max(len, i-m[newmask]);
            }
        }
        return len;
    }
};