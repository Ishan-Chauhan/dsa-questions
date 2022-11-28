class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        vector<vector<int>> ans;
        int n = m.size();
        map<int,int> a,b;
        for(int i=0;i<n;i++)
        {
            a[m[i][0]]++;
            a[m[i][1]]++;
            b[m[i][1]]++;
        }
        vector<int> x,y;
        for(auto i: a)
        {
            if(b[i.first]==0) x.push_back(i.first);
            else if(b[i.first]==1) y.push_back(i.first);
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};