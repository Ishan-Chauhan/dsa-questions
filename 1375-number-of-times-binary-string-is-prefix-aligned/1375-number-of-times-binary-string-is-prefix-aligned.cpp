class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        set<int> s;
        int n=flips.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            s.insert(flips[i]);
            if(*s.rbegin()==i+1) ans++;
        }
        return ans;
    }
};