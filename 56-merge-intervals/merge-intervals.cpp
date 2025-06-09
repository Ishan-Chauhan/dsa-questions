class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());

        vector<vector<int>> res;
        res.push_back(inter[0]);
        int x=0, n=inter.size();

        for(int i=1;i<n;i++)
        {
            if(inter[i][0]<=res[x][1])
            {
                res[x][1] = max(inter[i][1], res[x][1]);
            }
            else 
            {
                res.push_back(inter[i]);
                x++;
            }
        }
        return res;
    }
};