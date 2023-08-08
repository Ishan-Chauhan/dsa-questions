class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n=moves.size();
        if(n<5) return "Pending";
        
        vector<int> a(8,0), b(8,0);
        for(int i=0;i<n;i++)
        {
            vector<int>& x = (i%2==0)?a:b;
            int r=moves[i][0], c=moves[i][1];
            
            x[r]++;
            x[c+3]++;
            if(r==c) x[6]++;
            if(r+c==2) x[7]++;
        }
        
        for(int i=0;i<8;i++)
        {
            if(a[i]==3) return "A";
            if(b[i]==3) return "B";
        }
        
        return n==9?"Draw":"Pending";
        
    }
};