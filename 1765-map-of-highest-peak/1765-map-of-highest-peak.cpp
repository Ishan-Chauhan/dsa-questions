class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        
        vector<vector<int>> res(n, vector<int>(m, -1));
        
        queue<vector<int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1) q.push({i,j});
            }
        }
        
        vector<int> d{0,1,0,-1,0};
        
        int c=-1;
        while(q.size())
        {
            c++;
            int z=q.size();
            while(z--)
            {
                int x=q.front()[0];
                int y=q.front()[1];
                
                // cout<<x<<" "<<y<<" "<<c<<endl;
                
                q.pop();
                
                if(res[x][y]!=-1)
                continue;
                
                res[x][y]=c;
                
                for(int i=0;i<4;i++)
                {
                    int nx=x+d[i];
                    int ny=y+d[i+1];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && res[nx][ny]==-1) q.push({nx, ny});
                }
            }
        }
        return res;
    }
};