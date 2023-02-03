class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1)return s;
        if(n<=numRows)return s;
        string ans;
        int c=numRows-2,x=numRows-2,f=0,k=2;
        for(int i=0;i<numRows;i++)
        {
            if(i==0 || i==numRows-1)
            {
                for(int j=i;j<n;j+=(numRows*2)-2)
                    ans.push_back(s[j]);
            }
            else
            {
                int j=i;
                f=0;
                while(j<n)
                {
                    ans.push_back(s[j]);
                    if(f==0)
                    {
                        j+=c+x;
                        f=1;
                    }
                    else
                    {
                        j+=k;
                        f=0;
                    }
                }
                x--;
                c--;
                k+=2;
            }
        }
        return ans;
    }
};