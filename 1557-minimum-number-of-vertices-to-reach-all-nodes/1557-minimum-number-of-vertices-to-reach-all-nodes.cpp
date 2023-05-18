class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int len=edges.size();
        vector<int> v(n,0);
        for(int i=0;i<len;i++)
        {
            v[edges[i][1]]++;
        }
        vector<int> res;
        for(int i=0;i<n;i++) if(v[i]==0) res.push_back(i);
        return res;
    }
};