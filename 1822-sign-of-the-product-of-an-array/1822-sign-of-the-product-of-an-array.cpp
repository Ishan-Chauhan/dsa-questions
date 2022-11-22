class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0) ans*=-1;
            else if(nums[i]==0) return 0;
        }
        return ans;
    }
};