class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        int l = c.size();
        map<int,vector<int>> f,b;
        vector<int> v(n,0);
        queue<int> q;
        q.push(0);
        int ans = 0;
        
        for(int i=0;i<l;i++)
        {
            f[c[i][0]].push_back(c[i][1]);
            b[c[i][1]].push_back(c[i][0]);
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            v[curr]=1;
            
            for(auto i: f[curr])
            {
                if(v[i]==0)
                {
                    v[curr]=1;
                    ans++;
                    q.push(i);
                }
            }
            
            for(auto i: b[curr])
            {
                if(v[i]==0)
                {
                    v[curr]=1;
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};