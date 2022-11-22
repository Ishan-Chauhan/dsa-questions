class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]=1;
            if(nums[i]<0) nums[i]*=-1;
        }
        int ans = *min_element(nums.begin(),nums.end());
        if(m[ans]==1) return ans;
        return ans*-1;
    }
};