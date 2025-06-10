class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int prev = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prev){
                ans += prices[i] - prev;
                prev = prices[i];
            }
            else prev = min(prev, prices[i]);
        }

        return ans;
    }
};