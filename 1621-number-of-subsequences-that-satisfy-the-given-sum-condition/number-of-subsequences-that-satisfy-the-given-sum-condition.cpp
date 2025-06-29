class Solution {
public:
    int p(int x)
    {
        int m = 1000000007;
        int ans=1;
        long long b = 2;

        while(x)
        {
            if(x&1) ans = (ans*b)%m;
            b = (b*b) %m;
            x >>= 1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        int ans=0;
        int m = 1000000007;

        for(int i=0;i<n;i++)
        {
            long long x = nums[i];

            int idx = upper_bound(nums.begin(), nums.end(), target-x) - nums.begin();
            if(idx==n || nums[idx]>target-x) idx--;

            if(idx<i) break;
            // cout<<i<<" "<<idx<<endl;
            x = p(idx-i) % m;
            ans = (ans%m + x%m)%m;
        }
        return ans;
    }
};