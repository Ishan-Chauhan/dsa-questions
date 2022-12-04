class Solution {
public:
    int min(long a,long b)
    {
        return (a>b)?b:a;
    }
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> p(n,0);
        p[0] = nums[0];
        long sum = nums[0];
        for(int i=1;i<n;i++)
        {
            p[i] = p[i-1] + nums[i];
            sum += nums[i];
        }
        int ans = 0;
        for(int i=0;i<n-1;i++)
        {
            if(p[i]>=sum-p[i]) ans++;
        }
        return ans;
    }
};