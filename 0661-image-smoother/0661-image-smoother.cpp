class Solution {
public:
    int sol(vector<vector<int>>& img, int x, int y, int n, int m)
    {
        int c=0,ans=0;
        
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(x+i>=0 && x+i<n && y+j>=0 && y+j<m)
                {
                    c++;
                    ans+=img[x+i][y+j];
                }
            }
        }
        return ans/c;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n=img.size(), m=img[0].size();
        vector<vector<int>> res(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res[i][j] = sol(img,i,j,n,m);
            }
        }
        
        return res;
    }
};