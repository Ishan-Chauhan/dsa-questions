class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        map<vector<int>, int> m;
        for(auto&it :grid)
        {
            m[it]+=1;
        }
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                v.push_back(grid[j][i]);
            }
            if(m[v]!=0) ans+=m[v];
        }
        return ans;
    }
};