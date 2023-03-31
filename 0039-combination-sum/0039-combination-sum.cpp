class Solution {
public:
    int sum(vector<int> v)
    {
        int n=v.size(),sum=0;
        for(int i=0;i<n;i++)
            sum+=v[i];
        return sum;
    }
    void func(vector<vector<int>>& ans,vector<int> v,vector<int> c,int n,int i,int sz)
    {
        //cout<<n<<" ";
        if(n==0)
        {
            ans.push_back(c);
            return;
        }
        if(n<0 || i==sz)
            return;
        c.push_back(v[i]);
        func(ans,v,c,n-v[i],i,sz);
        c.pop_back();
        func(ans,v,c,n,i+1,sz);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int sz=candidates.size();
        func(ans,candidates,v,target,0,sz);
        return ans;
    }
};