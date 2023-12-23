class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;
        int n=path.size();
        if(n==1)return false;
        int x=0,y=0;
        s.insert({0,0});
        for(int i=0;i<n;i++)
        {
            if(path[i]=='N')x++;
            else if(path[i]=='S')x--;
            else if(path[i]=='E')y++;
            else y--;
            //cout<<x<<" "<<y<<endl;
            if(s.find({x,y})!=s.end())return true;
            else s.insert({x,y});
        }
        return false;
    }
};