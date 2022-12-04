class Solution {
public:
    int min(long a,long b)
    {
        return (a>b)?b:a;
    }
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long> p(n,0);
        p[0] = nums[0];
        long sum = nums[0];
        for(int i=1;i<n;i++)
        {
            p[i] = p[i-1] + nums[i];
            sum += nums[i];
        }
        int ans = INT_MAX;
        int temp,index=-1;
        for(int i=0;i<n;i++)
        {
            
            if(i!=n-1) temp = min(ans,abs(p[i]/(i+1)-(sum-p[i])/(n-i-1)));
            else temp = min(ans,sum/n);
            // cout<<temp<<" ";
            if(ans>temp) 
            {
                ans = temp;
                index = i;
            }
        }
        return index;
    }
};