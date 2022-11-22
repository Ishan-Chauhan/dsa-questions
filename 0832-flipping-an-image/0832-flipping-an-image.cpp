class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& v) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            reverse(v[i].begin(),v[i].end());
            for(int j=0;j<n;j++)
            {
                v[i][j] = (v[i][j]==0)?1:0;
            }
        }
        return v;
    }
};