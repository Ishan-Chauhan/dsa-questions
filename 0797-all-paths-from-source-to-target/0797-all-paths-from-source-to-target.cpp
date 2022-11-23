class Solution {
public:
    void sol(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& temp,int sc,int curr,int dt,vector<bool>& visited)
    {
        if(curr==dt)
        {
            temp.push_back(dt);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(visited[curr]==true) return;
        for(int i=0;i<graph[curr].size();i++)
        {
            visited[curr]=true;
            temp.push_back(curr);
            sol(graph,ans,temp,0,graph[curr][i],graph.size()-1,visited);
            temp.pop_back();
            visited[curr]=false;
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> visited(graph.size(),false);
        sol(graph,ans,temp,0,0,graph.size()-1,visited);
        return ans;
    }
};