class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({sr,sc});
        vector<int> d{1,0,-1,0,1};
        int xyz = image[sr][sc];
        
        while(!q.empty())
        {
            pair<int,int> temp = q.front();
            int x=temp.first, y=temp.second;
            q.pop();
            
            image[x][y] = color;
            
            for(int i=0;i<4;i++)
            {
                int dx = x+d[i];
                int dy = y+d[i+1];
                
                if(dx>=0 && dy>=0 && dx<n && dy<m && image[dx][dy]==xyz && image[dx][dy]!=color) q.push({dx,dy});
            }
        }
        
        return image;
    }
};