class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        int n=s.size();
        for(int i=0;i<n;i++)
            m[s[i]]++;
        vector<pair<int,char>> v;
        string ans;
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--)
        {
            for(int j=0;j<v[i].first;j++)
                ans.push_back(v[i].second);
        }
        return ans;
    }
};