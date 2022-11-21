class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int x = entrance[0];
        int y = entrance[1];
        int n = maze.size();
        int m = maze[0].size();
        int a,b,c=0;
        queue<vector<int>> q;
        vector<int> dir{0,1,0,-1,0};
        q.push({x,y,0});
        vector<int> temp;
        maze[x][y] = '+';
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            a = temp[0];
            b = temp[1];
            if((a!=x || b!=y) && (a==0 || b==0 || a==n-1 || b==m-1)) return temp[2];
            for(int i=0;i<4;i++)
            {
                if(a+dir[i]>=0 && a+dir[i]<n && b+dir[i+1]>=0 && b+dir[i+1]<m && maze[a+dir[i]][b+dir[i+1]]=='.')
                {
                    q.push({a+dir[i],b+dir[i+1],temp[2]+1});
                    maze[a+dir[i]][b+dir[i+1]]='+';
                }
                    
            }
        }
        return -1;
    }
};