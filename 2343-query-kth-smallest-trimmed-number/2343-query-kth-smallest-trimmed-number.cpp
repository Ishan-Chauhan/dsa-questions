class Solution {
public:
    priority_queue<pair<string,int>> sol(vector<string>& nums, int n, int m, int k, int trim)
    {
        // cout<<"helo"<<endl;
        priority_queue<pair<string,int>> pq;
        for(int i=0;i<n;i++)
        {
            string temp="";
            // for(int j=m-1;j>=m-trim;j--)
            // {
            //     temp = nums[i][j]+temp;
            // }
            
            for(int j=m-trim;j<=m-1;j++) temp+=nums[i][j];
            // cout<<temp<<" ";
            // int x = stoi(temp);
            // cout<<temp<<" "<<i<<" "<<k<<endl;
            pq.push({temp,i});
            
            if(pq.size()>k) pq.pop();
        }
        
        return pq;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int m = nums[0].size();
        int q = queries.size();
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i=0; i<q ; i++)
        {
            int k = queries[i][0];
            int trim = queries[i][1];
            
            priority_queue<pair<string,int>> pq = sol(nums,n,m,k, trim);
            ans.push_back(pq.top().second);
        }
        
        return ans;
    }
};