class Solution {
public:
    void sol(vector<int>& c,int i,int target,int n,vector<vector<int>> &v,vector<int> temp)
    {
        if(target<0) return;
        target -= c[i];
        temp.push_back(c[i]);
        if(target==0) 
        {
            v.push_back(temp);
            // temp.pop_back();
            return;   
        }
        for(int j=i+1;j<n;j++) 
        {
            if(j==i+1 || c[j]!=c[j-1]) sol(c,j,target,n,v,temp);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        int n=c.size();
        // set<vector<int>> st;
        vector<vector<int>> v;
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            if(i==0 || c[i]!=c[i-1])
            {
                sol(c,i,target,n,v,temp);
            }
        }
        // vector<vector<int>> v(st.begin(),st.end());
        return v;
    }
};