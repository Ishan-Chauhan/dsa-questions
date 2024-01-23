class Solution {
public:
    int countCollisions(string d) {
        int n=d.size(), ans=0;
        
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            if(d[i]=='L')
            {
                if(st.empty()) continue;
                else if(st.top()=='R') 
                {
                    ans+=2;
                    st.pop();
                    while(!st.empty() && st.top()=='R')
                    {
                        st.pop();
                        ans+=1;
                    }
                    st.push('S');
                }
                else if(st.top()=='S')
                {
                    ans+=1;
                    st.push('S');
                }
            }
            else if(d[i]=='R')
            {
                st.push(d[i]);
            }
            else
            {
                if(st.empty()) st.push(d[i]);
                else if(st.top()=='R') 
                {
                    while(!st.empty() && st.top()=='R')
                    {
                        st.pop();
                        ans+=1;
                    }
                    st.push('S');
                }
            }
        }
        return ans; // "SSRSSRLLRSLLRS  RSSRLRRRRLL  RRLSSRR"
    }
};