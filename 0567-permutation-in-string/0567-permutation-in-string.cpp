class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0,j=0,n=s2.size();
        map<char,int> m;
        for(int k=0;k<s1.size();k++) m[s1[k]]++;
        int c=m.size();
        while(j!=n)
        {
            //cout<<c<<" ";
            if(m.find(s2[j])==m.end())
            {
                j++;
                while(i!=j)
                {
                    if(m.find(s2[i])!=m.end())
                    {
                        m[s2[i]]++;
                        if(m[s2[i]]==1) c++;
                    }
                    i++;
                }
            }
            else if(m[s2[j]]==0)
            {
                while(s2[i]!=s2[j])
                {
                    m[s2[i]]++;
                    if(m[s2[i]]==1) c++;
                    i++;
                }
                m[s2[i]]++;
                c++;
                i++;
            }
            else
            {
                m[s2[j]]--;
                if(m[s2[j]]==0)c--;
                if(c==0) return true;
                j++;
            }
        }
        return false;
    }
};