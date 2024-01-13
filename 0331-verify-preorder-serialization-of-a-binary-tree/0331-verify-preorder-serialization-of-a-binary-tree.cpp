class Solution {
public:
    bool isValidSerialization(string pre) {
        int n=pre.size();
        stack<char> st;
        
        for(int i=0;i<n;i+=2)
        {
            if(pre[i]=='#')
            {
                while(!st.empty() && st.top()==pre[i])
                {
                    st.pop();
                    if(st.empty()) return false;
                    st.pop();
                }
                st.push(pre[i]);
            }
            else
            {
                while(pre[i]>='0' && pre[i]<='9') 
                {
                    i++;
                }
                i--;
                st.push('1');
            }
        }
        return (st.size()==1 && st.top()=='#');
    }
};