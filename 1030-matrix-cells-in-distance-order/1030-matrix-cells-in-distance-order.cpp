class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> v, ans;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                v.push_back({abs(rCenter-i)+abs(cCenter-j), i,j});
            }
        }
        
        sort(v.begin(), v.end());
        
        for(int i=0;i<v.size();i++)
        {
            ans.push_back({v[i][1], v[i][2]});
        }
        
        return ans;
    }
};