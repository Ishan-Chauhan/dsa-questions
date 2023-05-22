class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        vector<pair<int,int>> v;
        vector<int> ans;
        for(auto i:m)
            v.push_back({i.second,i.first});
        sort(v.begin(),v.end());
        //for(int i=0;i<v.size();i++)
          //  cout<<v[i].first<<" "<<v[i].second<<endl;
        for(int i=0;i<k;i++)
            ans.push_back(v[v.size()-i-1].second);
        return ans;
    }
};