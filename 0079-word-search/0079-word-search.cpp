class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int n, int m, int x, int sz)
    {
        // cout<<i<<" "<<j<<endl;
        if(x==sz) return true;
        if(i<0 || j<0 || i>=n || j>=m || word[x] != board[i][j]) return false;
        
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool ans = dfs(board,word,i,j+1,n,m,x+1,sz)||
               dfs(board,word,i+1,j,n,m,x+1,sz)||
               dfs(board,word,i-1,j,n,m,x+1,sz)||
               dfs(board,word,i,j-1,n,m,x+1,sz);
        
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int sz=word.size();
        int x=0;
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && dfs(board, word, i, j, n, m, x, sz)) return true;
            }
        }
        return false;
    }
};