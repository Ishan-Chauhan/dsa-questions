class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        map<int,vector<int>> m;
        for(int i=0;i<n;i++) m[arr[i]].push_back(i);
        
        vector<int> v(n,0);
        
        queue<vector<int>> q;
        q.push({0,0});
        v[0]=1;
        
        while(!q.empty())
        {
            int curr = q.front()[0];
            int step = q.front()[1];
            q.pop();
            // v[curr]=1;
            // cout<<arr[curr]<<" "<<curr<<" "<<step<<endl;
            
            if(curr==n-1) return step;
            
            for(auto& it:m[arr[curr]])
            {
                // if(it!=curr && v[it]==1) break;
                if(v[it]==0)
                {
                    v[it]=1;
                    q.push({it,step+1});
                }
            }
            m[arr[curr]]={};
            
            if(curr+1<=n-1 && v[curr+1]==0)
            {
                // cout<<arr[curr+1]<<" "<<step+1<<endl;
                v[curr+1]=1;
                q.push({curr+1,step+1});
            }
            if(curr-1>=0 && v[curr-1]==0)
            {
                v[curr-1]=1;
                q.push({curr-1,step+1});
            }
            // cout<<step<<" ";
        }
        
        return 0;
    }
};