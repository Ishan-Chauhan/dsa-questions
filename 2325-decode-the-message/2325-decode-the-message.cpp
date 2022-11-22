class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> m;
        m[' '] = ' ';
        string temp;
        int n=key.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(key[i])==m.end())
            {
                m[key[i]] = 'a'+ j;
                j++;
                if(j==26) j=0;
            }
        }
        for(int i=0;i<message.size();i++)
        {
            temp+=m[message[i]];
        }
        return temp;
    }
};