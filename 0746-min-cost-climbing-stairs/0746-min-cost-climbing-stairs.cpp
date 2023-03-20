class Solution {
public:
    vector<int> v;
    int sol(vector<int>& cost,int n,int i)
    {
        if(i==n-1 || i==n-2)
            return cost[i];
        if(v[i]==-1)
        {
            v[i+2]=sol(cost,n,i+2);
            v[i+1]=sol(cost,n,i+1);
        }
        return cost[i]+min(v[i+1],v[i+2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(),ans1,ans2;
        v.resize(n,-1);
        ans1=sol(cost,n,0);
        ans2=sol(cost,n,1);
        return ans1<ans2?ans1:ans2;
    }
};