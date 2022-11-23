class Solution {
public:
    bool c_row(vector<vector<char>> v)
    {
        for(int i=0;i<9;i++)
        {
            map<char,int> m;
            for(int j=0;j<9;j++)
            {
                m[v[i][j]]++;
            }
            for(auto x:m)
            {
                if(x.second>1 && x.first!='.')
                    return false;
            }
        }
        return true;
    }
    bool c_col(vector<vector<char>> v)
    {
        for(int i=0;i<9;i++)
        {
            map<char,int> m;
            for(int j=0;j<9;j++)
            {
                m[v[j][i]]++;
            }
            for(auto x:m)
            {
                if(x.second>1 && x.first!='.')
                    return false;
            }
        }
        return true;
    }
    bool c_box(vector<vector<char>> v)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                map<char,int> m;
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        m[v[i*3+k][j*3+l]]++;
                    }
                }
                for(auto x:m)
                {
                    if(x.second>1 && x.first!='.')
                        return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        /*if(c_box(board))
            cout<<3;
        if(c_row(board))
            cout<<1;
        if(c_col(board))
            cout<<2;*/
        return (c_row(board) && c_col(board) && c_box(board));
    }
};