class Solution {
public:
    int findpairs(vector<int>& nums, int n, int x)
    {
        int c=0;

        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=x)
            {
                c++;
                i++;
            }
        }
        return c;
    }
    int bs(vector<int>& nums, int n, int p)
    {
        int l=0, r=nums[n-1]-nums[0], mid, ans;

        while(l<=r)
        {
            // cout<<l<<" "<<r<<endl;
            mid = l + (r-l)/2;
            if(findpairs(nums, n, mid)>=p)
            {
                ans = mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        // cout<<ans<<endl;
        return ans;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int ans = bs(nums, n, p);

        return ans;
    }
};