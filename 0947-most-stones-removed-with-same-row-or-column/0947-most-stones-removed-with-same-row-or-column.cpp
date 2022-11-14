class Solution {
public:
    vector<int> p;
    int parent(int a)
    {
        return (p[a]<0) ? a:parent(p[a]);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        p.resize(n,-1);
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    int a = parent(i);
                    int b = parent(j);
                    if(a!=b)
                    {
                        // int temp = p[b];
                        p[a] += p[b];
                        p[b] = a;
                    }
                }
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++) 
        {
            if(p[i]<0) c++;
        }
        
        return n-c;
    }
};