class Solution {
public:
    int sol(vector<int>& nums, int i, int j)
    {
        if(i==j) return nums[i];
        
        int start = nums[i] - sol(nums, i+1, j);
        int end = nums[j] - sol(nums, i, j-1);
        
        return max(start, end);
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        int ans = sol(nums,0,n-1);
        
        return ans>=0;
    }
};