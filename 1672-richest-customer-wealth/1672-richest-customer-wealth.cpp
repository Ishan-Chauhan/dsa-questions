class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int c=0,ans=0;
        for(int i=0;i<n;i++)
        {
            c=0;
            for(int j=0;j<m;j++)
            {
                c+=a[i][j];
            }
            ans=max(c,ans);
        }
        return ans;
    }
};