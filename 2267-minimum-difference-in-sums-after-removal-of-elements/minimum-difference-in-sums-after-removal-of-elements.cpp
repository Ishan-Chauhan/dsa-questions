class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        n/=3;

        priority_queue<long long> maxi;
        priority_queue<long long, vector<long long>, greater<long long> > mini;

        long long sum=0, a=0, b=0;
        for(int i=0;i<n;i++) 
        {
            maxi.push(nums[i]);
            sum += nums[i];
        }
        a=sum;

        vector<long long> pre(n, 0);
        vector<long long> suf(n, 0);

        for(int i=n;i<2*n;i++)
        {
            if(nums[i]<maxi.top())
            {
                sum -= maxi.top();
                sum += nums[i];
                maxi.pop();
                maxi.push(nums[i]);
            }
            pre[i-n]=sum;
        }

        sum=0;
        for(int i=3*n-1;i>=2*n;i--) 
        {
            mini.push(nums[i]);
            sum += nums[i];
        }
        b=sum;

        for(int i=2*n-1;i>=n;i--)
        {
            if(nums[i]>mini.top())
            {
                sum -= mini.top();
                sum += nums[i];
                mini.pop();
                mini.push(nums[i]);
            }
            suf[i-n]=sum;
        }

        long long ans=min(a-suf[0], pre[n-1]-b);

        for(int i=0;i<n-1;i++)
        {
            ans = min(ans, pre[i]-suf[i+1]);
            // cout<<pre[i]<<" "<<suf[i+1]<<" "<<ans<<endl;
        }

        return ans;
    }
};