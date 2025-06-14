class Solution {
public:
    int minMaxDifference(int num) {
        string a,b;

        a=to_string(num);
        b=to_string(num);

        char x,y;

        for(int i=0;i<a.size();i++)
        {
            if(a[i]!='9')
            {
                x=a[i];
                break;
            }
        }

        for(int i=0;i<a.size();i++)
        {
            if(a[i]==x)
            {
                a[i]='9';
            }
        }

        for(int i=0;i<b.size();i++)
        {
            if(b[i]!='0')
            {
                y=b[i];
                break;
            }
        }

        for(int i=0;i<b.size();i++)
        {
            if(b[i]==y)
            {
                b[i]='0';
            }
        }

        return stoi(a)-stoi(b);
    }
};