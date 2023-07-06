class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int p=1, mod=1000000007;
        int n=nums.size();
        for(int i=0;i<n;i++) q.push(nums[i]);
        for(int i=0;i<k;i++)
        {
            int x=q.top();
            q.pop();
            q.push(x+1);
        }
        while(!q.empty())
        {
            long long x=(p%mod);
            x *= (q.top()%mod);
            p = (x)%mod;
            q.pop();
        }
        return p;
    }
};