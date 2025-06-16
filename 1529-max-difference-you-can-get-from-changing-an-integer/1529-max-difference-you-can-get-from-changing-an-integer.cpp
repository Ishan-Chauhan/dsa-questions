class Solution {
public:
    int max(string s)
    {
        int n=s.size();
        char x='$';

        for(int i=0;i<n;i++)
        {
            if(s[i]!='9')
            {
                x=s[i];
                break;
            }
        }
        if(x=='$') return stoi(s);

        for(int i=0;i<n;i++)
        {
            if(s[i]==x)
            {
                s[i]='9';
            }
        }
        return stoi(s);
    }

    int min(string s)
    {
        int n=s.size();
        char x='$';

        for(int i=1;i<n;i++)
        {
            if(s[i]!='0' && s[0]!=s[i])
            {
                x=s[i];
                break;
            }
        }
        if(x=='$') 
        {
            if(n==1 || s[1]=='0') 
            {
                s[0]='1';
                return stoi(s);
            }

            for(int i=0;i<n;i++) s[i]='1';
            return stoi(s);
        }

        if(s[0]=='1')
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]==x) s[i]='0';
            }
            return stoi(s);
        }
        // cout<<s<<endl;
        x=s[0];
        for(int i=0;i<n;i++)
        {
            if(s[i]==x)
            {
                s[i]='1';
            }
        }
        // cout<<s<<endl;
        return stoi(s);
    }

    int maxDiff(int num) {
        int a = max(to_string(num));
        int b = min(to_string(num));

        // cout<<a<<" "<<b;

        return a-b;
    }
};