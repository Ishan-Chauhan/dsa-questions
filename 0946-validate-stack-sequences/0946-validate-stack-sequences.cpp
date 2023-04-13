class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0, n=pushed.size(), m = popped.size();
        stack<int> st;
        
        while(i!=n && j!=m)
        {
            if(st.empty())
            {
                st.push(pushed[i]);
                i++;
            }
            else if(st.top()==popped[j])
            {
                while(!st.empty() && st.top()==popped[j])
                {
                    // cout<<st.top()<<" ";
                    st.pop();
                    j++;
                }
            }
            else
            {
                st.push(pushed[i]);
                i++;
            }
            // cout<<st.top()<<" ";
            if(i==n && st.top()!=popped[j]) return false;
        }
        
        while(!st.empty() && st.top()==popped[j])
        {
            // cout<<st.top()<<" ";
            st.pop();
            j++;
        }
        
        if(i==n && j==m) return true;
        
        return false;
    }
};