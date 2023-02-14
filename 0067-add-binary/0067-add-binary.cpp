class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int c=0,i;
        int n= a.size()<b.size()?a.size():b.size();
        for(i=0;i<n;i++)
        {
            if(a[i]=='0' && b[i]=='0')
            {
                if(c==0)
                {
                    ans.push_back('0');
                    c=0;
                }
                else
                {
                    ans.push_back('1');
                    c=0;
                }
            }
            else if(a[i]=='1' && b[i]=='1')
            {
                if(c==0)
                {
                    ans.push_back('0');
                    c=1;
                }
                else
                {
                    ans.push_back('1');
                    c=1;
                }
            }
            else
            {
                if(c==0)
                {
                    ans.push_back('1');
                    c=0;
                }
                else
                {
                    ans.push_back('0');
                    c=1;
                }
            }
        }
        //cout<<i<<endl;
        int m= a.size()>b.size()?a.size():b.size();
        if(m==a.size())
        {
            for(int j=i;j<m;j++)
            {
                if(a[j]=='1')
                {
                    if(c==1)
                    {
                        ans.push_back('0');
                        c=1;
                    }
                    else
                    {
                        ans.push_back('1');
                        c=0;
                    }
                }
                else
                {
                    //cout<<c<<" ";
                    if(c==1)
                    {
                        ans.push_back('1');
                        c=0;
                    }
                    else
                    {
                        ans.push_back('0');
                        c=0;
                    }
                }
            }
        }
        else
        {
            //cout<<i;
            for(int j=i;j<m;j++)
            {
                if(b[j]=='1')
                {
                    //cout<<c<<" ";
                    if(c==1)
                    {
                        ans.push_back('0');
                        c=1;
                    }
                    else
                    {
                        ans.push_back('1');
                        c=0;
                    }
                }
                else
                {
                    //cout<<c<<" ";
                    if(c==1)
                    {
                        ans.push_back('1');
                        c=0;
                    }
                    else
                    {
                        ans.push_back('0');
                        c=0;
                    }
                }
            }
        }
        if(c==1)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};