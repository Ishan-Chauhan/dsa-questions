class Solution {
public:
    int maxDifference(string s) {
        int n=s.size();

        vector<int> v(26, 0);
        int mx=INT_MIN, mn=INT_MAX;

        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(v[i]&1) mx=max(mx, v[i]);
            else mn = min(mn, v[i])==0 ? mn : min(mn, v[i]);
        }

        return mx-mn;
    }
};