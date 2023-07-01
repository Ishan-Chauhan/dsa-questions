class Solution {
public:
    int dfs(int i, vector<int>& cookies, vector<int>& dist, int k, int zero)
    {
        if(i==cookies.size()) return *max_element(dist.begin(), dist.end());
        
        int ans=INT_MAX;
        
        for(int j=0;j<k;j++)
        {
            zero -= dist[j]==0 ? 1:0;
            dist[j] += cookies[i];
            
            ans = min(ans, dfs(i+1, cookies, dist, k, zero));
            
            zero += dist[j]==0 ? 1:0;
            dist[j] -= cookies[i];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);
        return dfs(0,cookies,distribute,k,k);
    }
};