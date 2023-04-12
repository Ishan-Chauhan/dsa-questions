class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++)
        {
            string a;
            if(s[i]=='/')
                continue;
            while(i<s.size() && s[i]!='/')
            {
                a=a+s[i];
                i++;
            }
            if(a==".")
                continue;
            if(a=="..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
            {
                st.push(a);
            }
            //cout<<a<<" ";
            //cout<<st.top()<<" ";
        }
        string ans;
        while(!st.empty())
        {
            // cout<<st.top()<<" ";
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.size()==0)
            return "/";
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};