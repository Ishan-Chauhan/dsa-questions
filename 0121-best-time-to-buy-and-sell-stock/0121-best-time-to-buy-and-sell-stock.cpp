class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,p=prices[0],n=prices.size();
        for(int i=1;i<n;i++)
        {
            if(prices[i]<p)
                p=prices[i];
            else
            {
                ans=max(prices[i]-p,ans);
            }
        }
        return ans;
    }
};