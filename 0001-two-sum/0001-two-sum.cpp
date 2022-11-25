class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        vector<vector<int>> a;
        int n,l,r,m;
        for(int i=0;i<nums.size();i++)
            a.push_back({nums[i],i});
        sort(a.begin(),a.end());
        for(int i=0;i<nums.size();i++)
        {
            n=target-a[i][0];
            l=i,r=nums.size()-1;
            while(l<=r)
            {
                m=l+(r-l)/2+1;
                if(m>r)
                    m=r;
                if(a[m][0]==n)
                {
                    ans.push_back(a[m][1]);
                    ans.push_back(a[i][1]);
                    return ans;
                }
                else if(a[m][0]<n)
                    l=m+1;
                else 
                    r=m-1;
            }
        }
        return ans;
    }
};