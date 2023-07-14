class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int, int> dp;
        int n=arr.size(), mx=0;
        
        for(int i=0;i<n;i++)
        {
            dp[arr[i]] = dp[arr[i]-diff] + 1;
        }
        
        for(auto it: dp) mx = max(mx, it.second);
        
        return mx;
    }
};