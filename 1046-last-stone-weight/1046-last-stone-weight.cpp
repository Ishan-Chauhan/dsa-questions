class Solution {
public:
    int sol(vector<int> a)
    {
        int n=a.size();
        if(a[n-1]==-1)
            return 0;
        else if(a[n-2]==-1)
            return a[n-1];
        else
        {
            int x=a[n-1]-a[n-2];
            if(x!=0)
                a.push_back(x);
            a[n-1]=-1;
            a[n-2]=-1;
            sort(a.begin(),a.end());
            return sol(a);
        }
    }
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        sort(stones.begin(),stones.end());
        //vector<int> ans;
        int x=sol(stones);
        return x;
    }
};