class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(),c=-1;
        double m;
        double a,b;
        map<double,int> mp;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                a = points[j][1]-points[i][1];
                b = points[j][0]-points[i][0];
                if(b!=0)
                {
                    m=a/b;
                }
                else
                {
                    m=1e9;
                }
                if(mp[m]==0) mp[m]=2;
                else mp[m]++;
            }
            for(auto it:mp) c = max(c,it.second);
            mp.clear();
        }
        return c==-1?1:c;
    }
};