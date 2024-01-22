class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        
        int x=1, y=1, hx=1, hy=1;
        
        for(int i=1;i<h.size();i++)
        {
            if(h[i]==h[i-1]+1)
            {
                x++;
                hx = max(hx, x);
            }
            else x=1;
        }
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1]+1)
            {
                y++;
                hy = max(hy, y);
            }
            else y=1;
        }
        
        int side = min(hx, hy) + 1;
        
        return side*side;
    }
};