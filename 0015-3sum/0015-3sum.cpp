class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(),j,k;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1])continue;
            j=i+1;
            k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[k]);
                    ans.push_back(t);
                    j++;
                    k--;
                    while(k!=-1 && nums[k+1]==nums[k])k--;
                    while(j!=n && nums[j-1]==nums[j])j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                    while(k!=-1 && nums[k+1]==nums[k])k--;
                }
                else
                {
                    j++;
                    while(j!=n && nums[j-1]==nums[j])j++;
                }
            }
        }
        return ans;
    }
};