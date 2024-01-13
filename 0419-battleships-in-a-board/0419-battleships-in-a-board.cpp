class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        int n=board.size(), m= board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X' && (i==0 || board[i-1][j]!='X') && (j==0 || board[i][j-1]!='X'))
                    ans+=1;
            }
                        
        }
        return ans;
    }
};