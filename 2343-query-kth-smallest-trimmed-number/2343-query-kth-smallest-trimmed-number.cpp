class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        
        int n=q.size();
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            int k=q[i][0];
            int t=q[i][1];
            priority_queue<pair<string, int>> pq;
            
            for(int j=0;j<nums.size();j++)
            {
                string str = nums[j].substr(nums[j].size()-t,t);
                
                pq.push({str, j});
                
                if(pq.size()>k) pq.pop();
            }
            
            res.push_back(pq.top().second);
        }
        
        return res;
    }
};