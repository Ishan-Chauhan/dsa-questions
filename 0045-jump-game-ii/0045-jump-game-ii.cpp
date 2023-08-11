class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n-1;i++)
        {
            nums[i] = max(i+nums[i], nums[i-1]);
        }
        
        int id=0, ans=0;
        while(id<n-1)
        {
            id = nums[id];
            ans++;
        }
        
        return ans;
    }
};