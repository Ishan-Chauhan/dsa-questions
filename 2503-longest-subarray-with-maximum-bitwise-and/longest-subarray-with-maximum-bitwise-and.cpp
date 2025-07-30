class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int c=0,i=0,ans=0;

        while(i<n)
        {
            if(nums[i]==maxi)
            {
                c++;
                ans = max(ans, c);
            }
            else c=0;

            i++;
        }
        return ans;
    }
};