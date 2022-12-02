class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        set<char> a,b;
        vector<int> x(26),y(26);
        for(int i=0;i<n;i++) 
        {
            a.insert(word1[i]);
            x[word1[i]-'a']++;
        }
        for(int i=0;i<m;i++) 
        {
            b.insert(word2[i]);
            y[word2[i]-'a']++;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        return (a==b && x==y);
    }
};