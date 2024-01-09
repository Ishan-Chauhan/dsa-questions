class Solution {
public:
    long long min(long long a, long long b)
    {
        return a<b? a: b;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>> v(26, vector<long long>(26, 1e9));
        
        for(int i=0;i<26;i++) v[i][i]=0;
        
        int n=original.size();
        for(int i=0;i<n;i++) 
            v[original[i]-'a'][changed[i]-'a']=min(v[original[i]-'a'][changed[i]-'a'],cost[i]);
        
        for (int k=0;k<26;k++) 
        {
            for (int i = 0; i < 26; i++) 
            {
                for (int j = 0; j < 26; j++) 
                {
                    if (v[i][k]!=1e9 && v[k][j]!=1e9 && v[i][k]+v[k][j]<v[i][j])
                        v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
        
        n=source.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[source[i]-'a'][target[i]-'a']==1e9) return -1;
            ans+=v[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};