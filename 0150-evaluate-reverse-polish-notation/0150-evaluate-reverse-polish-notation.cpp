class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long long> st;
        int a,b;
        long long ans;
        for(int i=0;i<n;i++)
        {
            if(isdigit(tokens[i][0]) || tokens[i].size()>1) st.push(stoi(tokens[i]));
            // else if(tokens[i].size()>1)
            else
            {
                if(tokens[i][0]=='*')
                {
                    a = st.top();
                    st.pop();
                    b= st.top();
                    st.pop();
                    ans = a;
                    ans *= b;
                    st.push(ans);
                }
                else if(tokens[i][0]=='/')
                {
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(b/a);
                }
                else if(tokens[i][0]=='+')
                {
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    ans = a;
                    ans += b;
                    st.push(ans);
                }
                else
                {
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.pop();
                    st.push(b-a);
                }
                // cout<<a<<" "<<b<<" "<<st.top()<<endl;
            }
        }
        a = st.top();
        st.pop();
        return a;
    }
};