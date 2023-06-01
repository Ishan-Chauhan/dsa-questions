class Solution {
public:
    int isvalid(vector<vector<int>>& v,int i,int j,int n,vector<vector<bool>>& visit)
    {
        return (i>-1 && j>-1 && i<n && j<n && v[i][j]==0 && visit[i][j]==false);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        int n=v.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        int ans=0;
        if(v[0][0]==0)
        {
            q.push({0,0});
            visited[0][0]=true;
        }
        while(!q.empty())
        {
            ans++;
            int a=q.size();
            for(int i=0;i<a;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                int k=p.first,l=p.second;
                if(k==n-1 && l==n-1) return ans;
                for(int c=k-1;c<=k+1;c++)
                {
                    for(int d=l-1;d<=l+1;d++)
                    {
                        if(isvalid(v,c,d,n,visited))
                        {
                            visited[c][d]=true;
                            q.push({c,d});
                        }
                    }
                }
            }
        }
        return -1;
    }
};