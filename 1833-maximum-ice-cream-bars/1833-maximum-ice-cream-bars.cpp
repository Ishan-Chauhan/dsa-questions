class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size(), c=0;
        for(int i=0;i<n;i++)
        {
            if(costs[i]>coins) break;
            c++;
            coins-=costs[i];
        }
        return c;
    }
};