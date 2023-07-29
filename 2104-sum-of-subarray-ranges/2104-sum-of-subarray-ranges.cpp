class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        
        stack<int> st;
        vector<int> ps(n,-1), pg(n,-1), ns(n,n), ng(n,n);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            
            if(st.empty())
            {
                // ps[i]=-1;
            }
            else
            {
                ps[i]=st.top();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            
            if(st.empty())
            {
                // pg[i]=-1;
            }
            else
            {
                pg[i]=st.top();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++)
        {
            int next = nums[i];
            if (st.empty()) 
            {
                st.push(i);
                continue;
            }


            while (!st.empty() && nums[st.top()] > next)
            {
                ns[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++)
        {
            int next = nums[i];
            if (st.empty()) 
            {
                st.push(i);
                continue;
            }


            while (!st.empty() && nums[st.top()] < next)
            {
                ng[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        long long ans = 0;
        
        for(int i=0;i<n;i++)
        {
            // cout<<ps[i]<<" "<<ns[i]<<" "<<pg[i]<<" "<<ng[i]<<endl;
            long long mini = (i-ps[i])*(ns[i]-i);
            long long maxi = (i-pg[i])*(ng[i]-i);
            
            // cout<<mini<<" "<<maxi<<endl;
            
            ans += (maxi-mini)*nums[i];
        }
        
        return ans;
    }
};