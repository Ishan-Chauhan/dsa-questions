class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        
        int sum=0, flast=0, fnext, ans;
        
        for(int i=0;i<n;i++) 
        {
            sum+=nums[i];
            flast+=i*nums[i];
        }
        ans=flast;
        
        for(int i=1;i<n;i++)
        {
            fnext = flast + sum - n*nums[n-i];
            ans=max(ans,fnext);
            flast=fnext;
        }
        return ans;
    }
};