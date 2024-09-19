class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> res;

        if(s.size()==0) return res;

        if(s.size()==1)
        {
            res.push_back(stoi(s));
            return res;
        }

        if(s.size()==2 && isdigit(s[0]))
        {
            res.push_back(stoi(s));
            return res;
        }

        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];

            if(isdigit(ch)) continue;
            
            vector<int> left = diffWaysToCompute(s.substr(0, i));
            vector<int> right = diffWaysToCompute(s.substr(i+1));

            for(int j=0;j<left.size();j++)
            {
                for(int k=0;k<right.size();k++)
                {
                    if(ch=='+')
                    {
                        res.push_back(left[j]+right[k]);
                    }
                    else if(ch=='-')
                    {
                        res.push_back(left[j]-right[k]);
                    }
                    else
                    {
                        res.push_back(left[j]*right[k]);
                    }
                    
                }
            }

        }
        return res;
    }
};