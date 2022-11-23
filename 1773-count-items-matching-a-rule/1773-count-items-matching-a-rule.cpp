class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int j;
        if(ruleKey=="type") j=0;
        else if(ruleKey=="color") j=1;
        else j=2;
        
        int n=items.size(),c=0;
        for(int i=0;i<n;i++)
        {
            if(items[i][j]==ruleValue) c++;
        }
        return c;
    }
};