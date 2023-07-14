class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size(), ans=0;
        vector<int> v;
        v.push_back(1);
        
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1]) v[v.size()-1]++;
            else v.push_back(1);
        }
        
        if(v.size()==1) return 0;
        
        for(int i=1;i<v.size();i++)
        {
            ans += min(v[i], v[i-1]);
        }
        
        return ans;
    }
};