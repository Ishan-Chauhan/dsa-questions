class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size(),i=0,j=0,x=0;
        map<string,int> m;
        string temp;
        while(j!=n)
        {
            if(x<9)
            {
                temp.push_back(s[j]);
                x++;
            }
            else
            {
                temp.push_back(s[j]);
                x++;
                m[temp]++;
                temp.erase(temp.begin());
            }
            j++;
        }
        vector<string> res;
        for(auto i:m)
        {
            if(i.second>1)
                res.push_back(i.first);
        }
        return res;
    }
};