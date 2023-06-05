class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==2)
            return true;
        vector<int> v=coordinates[0];
        int y=coordinates[1][1]-v[1];
        int x=coordinates[1][0]-v[0];
        if(x!=0)
        {
            float m=float(y)/x;
            for(int i=2;i<n;i++)
            {
                int y1=coordinates[i][1]-v[1];
                int x1=coordinates[i][0]-v[0];
                if(x1==0)
                    return false;
                float m1=float(y1)/x1;
                //cout<<m1<<" ";
                if(m1!=m)
                    return false;
            }
        }
        else
        {
            for(int i=2;i<n;i++)
            {
                int x1=coordinates[i][0]-v[0];
                if(x1!=0)
                    return false;
            }
        }
        return true;
    }
};