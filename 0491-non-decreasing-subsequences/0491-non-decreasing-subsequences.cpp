class Solution {
public:
    int c=0;
    set<vector<int>> ans;
    void sol(int i, int n, vector<int>& nums, int prev, vector<int> v)
    {
        if(i==n) return;
        if(v.size()==0)
        {
            sol(i+1,n,nums,prev,v);
            v.push_back(nums[i]);
            sol(i+1,n,nums,v[v.size()-1],v);
        }
        else if(nums[i]>=prev)
        {
            // cout<<1;
            sol(i+1,n,nums,v[v.size()-1],v);
            v.push_back(nums[i]);
            ans.insert(v);
            sol(i+1,n,nums,v[v.size()-1],v);
        }
        else
        {
            sol(i+1,n,nums,v[v.size()-1],v);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        sol(0,n,nums,-101,temp);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
};