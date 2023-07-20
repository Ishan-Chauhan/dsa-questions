class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size(), f=0;
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            f=0;
            while(!st.empty() && a[i]<0 && st.top()>0)
            {
                if(abs(a[i]) > st.top())
                {
                    st.pop();
                    continue;
                }
                else if(abs(a[i]) == st.top())
                {
                    st.pop();
                }
                f=1;
                break;
            }
            
            if(!f) st.push(a[i]);
        }
        
        n=st.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--)
        {
            res[i] = (st.top());
            st.pop();
        }
        return res;
    }
};