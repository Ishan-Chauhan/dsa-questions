class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int r=0;
        for(int i=0;i<n;i++)
        {
            if(i>r) return false;
            r = max(r,i+nums[i]);
            if(r>=n-1) return true;
        }
        return true;
    }
};