class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int m = 1e9+7;
        stack<int> s;
        int n = arr.size();
        
        vector<int> dp(n,0);
        
        int sum=0;
        int t = 0;
        
        for(int i=0;i<n;i++)
        {
            t=0;
            while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
            
            if(s.empty())
            {
                t = ((i+1)*arr[i]%m)%m;
            }
            else
            {
                t = (dp[s.top()] + (i-s.top())*arr[i])%m;
            }
            
            sum = (sum%m+t%m)%m;
            dp[i]=t;
            s.push(i);
            // cout<<t<<" ";
        }
        return sum;
    }
};