class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<pair<int,int>> cells(n*n+1);
        vector<int> cols(n);
        iota(cols.begin(), cols.end(), 0);
        int x=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(auto col: cols)
            {
                cells[x++] = {i, col};
                // cout<<i<<" "<<col<<endl;
            }
            reverse(cols.begin(), cols.end());
        }
        
        vector<int> visited(n*n+1, -1);
        queue<int> q;
        q.push(1);
        // int steps=1;
        visited[1] = 0;
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            if(curr == n*n) return visited[curr];
            
            for(int next = curr+1; next<=min(curr+6, n*n); next++)
            {
                auto [row, col] = cells[next];
                int dest = board[row][col]==-1 ? next : board[row][col];
                if(visited[dest]==-1)
                {
                    q.push(dest);
                    visited[dest] = visited[curr]+1;
                    // cout<<curr<<" "<<dest<<" "<<visited[dest]<<endl;
                }
            }
        
        }
        
        return -1;
    }
};