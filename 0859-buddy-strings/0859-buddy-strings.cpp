class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size(), m=goal.size();
        if(n!=m) return false;
        
        if(s==goal)
        {
            vector<int> a(26,0);
            for(int i=0;i<n;i++)
            {
                a[s[i]-'a']++;
                if(a[s[i]-'a']==2) return true;
            }
        }
        
        vector<int> a;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i]) a.push_back(i);
        }
        
        return (a.size()==2)&&(s[a[0]]==goal[a[1]])&&(s[a[1]]==goal[a[0]]);
    }
};