class Solution {
private:
    string rle(string& s)
    {
        int n=s.size();
        char ch=s[0];
        int c=1;
        string res;
        
        for(int i=1;i<n;i++)
        {
            if(ch==s[i])
            {
                c++;
            }
            else
            {
                res += to_string(c);
                res += ch;
                ch = s[i];
                c=1;
            }
        }
        res += to_string(c);
        res += ch;

        return res;

    }
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=0;i<n-1;i++)
        {
            ans = rle(ans);
            // cout<<ans<<endl;
        }
        return ans;
    }
};