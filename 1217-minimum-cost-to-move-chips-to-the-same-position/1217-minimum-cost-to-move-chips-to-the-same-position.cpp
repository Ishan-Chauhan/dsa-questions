class Solution {
public:
    int minCostToMoveChips(vector<int>& v) {
        int e=0,o=0,n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]&1) o++;
            else e++;
        }
        if(o>e) return e;
        return o;
    }
};