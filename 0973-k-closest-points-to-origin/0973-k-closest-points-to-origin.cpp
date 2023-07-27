class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<vector<int>> st;
        vector<vector<int>> ans;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            st.insert({dis, points[i][0], points[i][1]});
        }
        for(auto it=st.begin(); it!=st.end(); it++)
        {
            vector<int> temp = *it;
            // cout<<temp[0]<<" ";
            ans.push_back({temp[1], temp[2]});
            k--;
            if(k==0) break;
        }
        return ans;
    }
};