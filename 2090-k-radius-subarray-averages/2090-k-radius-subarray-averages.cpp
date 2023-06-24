class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        k*=2;
        k+=1;
        int n=nums.size();
        vector<int> ans(n,-1);
        long long sum=0;
        
        int i=0,j=0;
        while(j<n)
        {
            if(j-i+1<k)
            {
                sum+=nums[j];
                j++;
            }
            else
            {
                sum+=nums[j];
                ans[j-(k-1)/2] = sum/k;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};