class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> v(n, vector<int>(n , 0));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});
        v[0][0]=1;

        vector<int> dir{0,1,0,-1,0};
        int ans=0;

        while(!pq.empty())
        {
            int ele = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            // cout<<ele<<" "<<x<<" "<<y<<endl;

            ans = max(ans, ele);

            if(x==n-1 && y==n-1) return ans;

            for(int i=0;i<4;i++)
            {
                int nx=x+dir[i];
                int ny=y+dir[i+1];

                if(nx>=0 && ny>=0 && nx<n && ny<n && v[nx][ny]==0)
                {
                    v[nx][ny]=1;
                    pq.push({grid[nx][ny],nx,ny});
                }
            }
        }
        return -1;
    }
};