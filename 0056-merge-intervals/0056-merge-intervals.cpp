class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> res;
        sort(v.begin(), v.end());
        
        res.push_back(v[0]);
        int x=0;
        
        for(int i=1;i<n;i++)
        {
            if(v[i][0] <= res[x][1]) res[x][1] = max(res[x][1], v[i][1]);
            else
            {
                res.push_back(v[i]);
                x++;
            }
        }
        return res;
    }
};