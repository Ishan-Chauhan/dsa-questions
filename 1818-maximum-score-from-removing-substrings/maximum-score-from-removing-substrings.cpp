class Solution {
public:
    int point(string& s, char a, char b, int x)
    {
        int n=s.size(), ans=0;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) 
            {
                st.push(s[i]);
                continue;
            }
            if(s[i]==b && st.top()==a)
            {
                st.pop();
                ans += x;
            }
            else st.push(s[i]);
        }
        s="";
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        string temp = s;

        if(x>=y)
        {
            ans += point(temp, 'a', 'b', x);
            ans += point(temp, 'a', 'b', y);
        }
        else 
        {
            ans += point(temp, 'b', 'a', y);
            ans += point(temp, 'b', 'a', x);
        }

        return ans;
    }
};