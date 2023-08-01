class Solution {
public:
    void sol(vector<vector<int>>& ans, vector<int>& temp, int n, int k, int i)
    {
        // cout<<i<<" ";
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }
        // 1 2 3 4 5 6
        for(int j=i; j<=n; j++)
        {
            temp.push_back(j);
            sol(ans, temp, n, k-1, j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sol(ans, temp, n, k, 1);
        
        return ans;
    }
};