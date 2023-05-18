class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        int len=edges.size();
        for(int i=0;i<len;i++)
        {
            m[edges[i][1]]++;
        }
        vector<int> res;
        for(int i=0;i<n;i++) if(m[i]==0) res.push_back(i);
        return res;
    }
};