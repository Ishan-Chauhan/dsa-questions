class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //sort(coins.begin(),coins.end());
        int n=coins.size();
        // vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        // int ans = sol(coins,amount,n-1,dp);
        vector<int> prev(amount+1), curr(amount+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0) curr[j]=1;
                
                else if(i==0) curr[j]=0;
                
                else
                {
                    if(j<coins[i-1]) curr[j] = prev[j];
                    else
                    {
                        curr[j] = prev[j] + curr[j-coins[i-1]];
                    }
                }
            }
            prev = curr;
        }
        return curr[amount];
    }
};