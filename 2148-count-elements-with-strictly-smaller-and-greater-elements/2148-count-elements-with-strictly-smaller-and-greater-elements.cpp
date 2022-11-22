class Solution {
public:
    int countElements(vector<int>& nums) {
        vector<pair<int,int>> v;
        int n=nums.size(),c=0;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<n-1;i++)
        {
            if(v[i].first>v[0].first && v[i].first<v[n-1].first) c++;
        }
        return c;
    }
};