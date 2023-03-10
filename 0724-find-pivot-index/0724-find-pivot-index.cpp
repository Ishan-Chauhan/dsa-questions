class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n,0), s(n,0);
        
        int sum = nums[0];
        p[0] = nums[0];
        
        for(int i=1;i<n;i++)
        {
            p[i] = p[i-1] + nums[i];
            sum += nums[i];
        }
        
        if(sum-nums[0]==0) return 0;
        
        for(int i=1;i<n;i++)
        {
            if(p[i-1]==sum-p[i]) return i;
        }
        
        return -1;
    }
};