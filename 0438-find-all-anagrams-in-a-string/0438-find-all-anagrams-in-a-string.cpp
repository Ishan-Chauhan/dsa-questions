class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0,n=s.size();
        map<char,int> m;
        for(int k=0;k<p.size();k++) m[p[k]]++;
        int c=m.size();
        int x=c;
        vector<int> res;
        //cout<<c;
        while(j!=n)
        {
            //if(c==0) c=x;
            if(m.find(s[j])==m.end())
            {
                j++;
                while(i!=j)
                {
                    //cout<<i<<" "<<j<<" ";
                    if(m.find(s[i])!=m.end())
                    {
                        m[s[i]]++;
                        if(m[s[i]]==1) c++;
                    }
                    i++;
                }
                //cout<<i<<" "<<j<<endl;
                //cout<<c;
            }
            else if(m[s[j]]==0)
            {
                while(s[i]!=s[j])
                {
                    //if(m.find(s[i])!=m.end())
                    //{
                        m[s[i]]++;
                        if(m[s[i]]==1) c++;
                    //}
                    i++;
                }
                m[s[i]]++;
                if(m[s[i]]==1) c++;
                i++;
            }
            else 
            {
                m[s[j]]--;
                if(m[s[j]]==0) c--;
                if(c==0) res.push_back(i);
                j++;
            }
            //cout<<c<<" ";
        }
        return res;
    }
};