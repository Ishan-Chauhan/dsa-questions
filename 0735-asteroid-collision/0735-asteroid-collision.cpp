class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size(), f=0;
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            f=0;
            if(st.empty()) st.push(a[i]);
            
            else if(a[i]<0 && st.top()>0)
            {
                while(!st.empty() && a[i]<0 && st.top()>0)
                {
                    if(abs(a[i]) > st.top()) st.pop();
                    else if(abs(a[i]) == st.top()) 
                    {
                        f=1;
                        st.pop();
                        break;
                    }
                    else break;
                }
                if(st.empty() && f==0) st.push(a[i]);
                else if(!st.empty() && a[i]*st.top()>0 && f==0) st.push(a[i]);
            }
            
            else st.push(a[i]);
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