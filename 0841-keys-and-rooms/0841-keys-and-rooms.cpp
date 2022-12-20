class Solution {
public:
    void sol(vector<vector<int>>& rooms, vector<int>& v, int i, int *c)
    {
        if(v[i]==1) return;
        v[i]=1;
        (*c)++;
        for(int j=0;j<rooms[i].size();j++) sol(rooms,v,rooms[i][j],c);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> v(n,0);
        int c=1;
        v[0]=1;
        for(int i=0;i<rooms[0].size();i++)
        {
            sol(rooms, v, rooms[0][i], &c);
        }
        return c==n;
    }
};