class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> v(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0) v[i][j] = 0;
                else if(text1[i-1] == text2[j-1]) v[i][j] = 1 + v[i-1][j-1];
                else v[i][j] = max(v[i][j-1], v[i-1][j]);
            }
        }
        return v[n][m];
    }
};