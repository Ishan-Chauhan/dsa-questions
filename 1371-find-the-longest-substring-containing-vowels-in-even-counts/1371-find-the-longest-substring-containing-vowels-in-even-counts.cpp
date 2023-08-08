class Solution {
public:
    int findTheLongestSubstring(string& s) {
        int n=s.size();
        int len=0;
        int mask=0;
        int c[] = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
        vector<int> m(32, -1);
        
        for(int i=0;i<n;i++)
        {
            mask ^= c[s[i]-'a'];
            if(mask!=0 && m[mask]==-1)
            {
                m[mask] = i;
            }
            len = max(len, i-m[mask]);
        }
        
        return len;
    }
};