class Solution {
public:
    vector<int> ans;
    void sol(int i, vector<vector<int>>& edge,string& labels,int prev,vector<int>& temp)
    {
        for(auto &it: edge[i])
        {
            if(it!=prev)
            {
                vector<int> a(26,0);
                sol(it,edge,labels,i,a);
                for(int i=0;i<26;i++)
                {
                    temp[i]+=a[i];
                }
            }
        }
        temp[labels[i]-'a']++;
        ans[i]=temp[labels[i]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        int m = edges.size();
        vector<vector<int>> edge(n);
        for(int i=0;i<m;i++)
        {
            edge[edges[i][1]].push_back(edges[i][0]);
            edge[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> temp(26,0);
        sol(0,edge,labels,-1,temp);
        return ans;
    }
};