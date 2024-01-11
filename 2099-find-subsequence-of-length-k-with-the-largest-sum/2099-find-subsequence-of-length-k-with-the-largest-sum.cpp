class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> q;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            q.push({nums[i],i});
        }
        vector<int> res,ind;
        for(int i=0;i<k;i++)
        {
            ind.push_back(q.top().second);
            q.pop();
        }
        sort(ind.begin(),ind.end());
        for(int i=0;i<k;i++)
        {
            res.push_back(nums[ind[i]]);
        }
        return res;
    }
};