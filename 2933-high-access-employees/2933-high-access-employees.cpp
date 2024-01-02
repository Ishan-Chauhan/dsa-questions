class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& at) {
        
        vector<string> res;
        
        sort(at.begin(), at.end());
        int n=at.size();
        int ct=0;
        
        if(n<3) return res;
        
        int i=0, j=2;
        
        while(j<n)
        {
            if(at[i][0]==at[j][0])
            {
                // cout<<at[i][1]<<" "<<at[j][1]<<endl;
                if(at[i][1].substr(0,2)==at[j][1].substr(0,2))
                {
                    if(ct==0 || res[ct-1]!=at[i][0]) 
                    {
                        res.push_back(at[i][0]);
                        ct++;
                    }
                }
                else if(stoi(at[i][1].substr(0,2))-stoi(at[j][1].substr(0,2))==-1 && stoi(at[i][1].substr(2,2))-stoi(at[j][1].substr(2,2))>0)
                {
                    if(ct==0 || res[ct-1]!=at[i][0]) 
                    {
                        res.push_back(at[i][0]);
                        ct++;
                    }
                }
            }
            i++;
            j++;
        }
        
        return res;
    }
};