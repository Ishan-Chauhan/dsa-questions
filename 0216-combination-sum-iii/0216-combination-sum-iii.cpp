class Solution {
public:
    void sol(int i,int n, int k, vector<int>& temp,vector<vector<int>>& res)
    {
        if(n==0 && k==0) 
        {
            res.push_back(temp);
            return;
        }
        if(i>9 || n<0) return;
        
        temp.push_back(i);
        sol(i+1, n-i, k-1, temp, res);
        temp.pop_back();
        sol(i+1,n,k,temp,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        
        sol(1,n,k,temp,res);
        
        return res;
    }
};