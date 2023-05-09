class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,r=m-1,t=0,b=n-1;
        vector<int> a;
        while(l<=r && t<=b)
        {
            for(int i=l;i<=r;i++)
                a.push_back(matrix[t][i]);
            t++;
            if(l>r || t>b)
                break;
            for(int i=t;i<=b;i++)
                a.push_back(matrix[i][r]);
            r--;
            if(l>r || t>b)
                break;
            for(int i=r;i>=l;i--)
                a.push_back(matrix[b][i]);
            b--;
            if(l>r || t>b)
                break;
            for(int i=b;i>=t;i--)
                a.push_back(matrix[i][l]);
            l++;
        }
        return a;
    }
};