class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size(),sum=0,size=INT_MAX,ans=0;
        while(j!=n)
        {
            sum+=nums[j];
            if(sum<target) j++;
            else
            {
                // size = min(size, j-i+1);
                while(sum>=target)
                {
                    size = min(size, j-i+1);
                    sum-=nums[i];
                    i++;
                }
                // size = min(size, j-i);
                j++;
            }
        }
        if(size==INT_MAX) return 0;
        return size;
    }
};