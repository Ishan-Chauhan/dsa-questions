class Solution {
public:
    string getHint(string s, string g) {
        int n = g.size();
        map<char,int> m, mp;
        int a=0, b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==g[i]) a++;
            else
            {
                m[s[i]]++;
                mp[g[i]]++;
            }
        }
        for(auto it: mp)
        {
            if(m[it.first]>0)
            {
                int x = min(m[it.first],mp[it.first]);
                b += x;
            }
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};