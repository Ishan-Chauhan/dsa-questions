class Solution {
public:
    vector<vector<int>> dp;
    int sol(vector<int>& coins, int amount, int i)
    {
        if(amount<0) return 1e9;
        if(amount==0) return 0;
        if(i==0)
        {
            if(amount%coins[i]==0) return dp[amount][i]=amount/coins[i];
            return 1e9;
        }
        if(dp[amount][i]!=-1) return dp[amount][i];
        
        int take = sol(coins,amount-coins[i], i);
        int not_take = sol(coins,amount,i-1);
        
        // if(take==-1 && not_take==-1) return ;
        // if(take==-1) return not_take;
        // if(not_take==-1) return take;
        
        // cout<<min(take+1,not_take);
        return dp[amount][i] = min(1+take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        dp.resize(amount+1, vector<int>(n,-1));
            
        int ans = sol(coins,amount, n-1);
        if(ans>=1e9) return -1;
        return ans;
    }
};