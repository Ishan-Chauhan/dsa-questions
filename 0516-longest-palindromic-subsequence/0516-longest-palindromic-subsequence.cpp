class Solution {
public:
    vector<vector<int>> v;
    string s1,s2;
    int sol(int n,int m)
    {
        if(n==-1 || m==-1)return 0;
        if(v[n][m]!=-1)return v[n][m];
        if(s1[n]==s2[m])return v[n][m]=1+sol(n-1,m-1);
        return v[n][m]=max(sol(n-1,m),sol(n,m-1));

    }    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int m=n;
        s1=s;
        reverse(s.begin(),s.end());
        s2=s;
        v.resize(n,vector<int>(m,-1));
        return sol(n-1,m-1);
    }
};

