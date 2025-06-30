class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans=0;
        int i=0,j=0, n=nums.size();

        while(j<n)
        {
            if(nums[j]-nums[i]==0) 
            {
                j++;
            }
            else if(nums[j]-nums[i]==1) 
            {
                ans = max(ans, j-i+1);
                j++;
            }
            else
            {
                while(nums[j]-nums[i]>1) i++;
            }
            // j++;
        }
        return ans;
    }
};