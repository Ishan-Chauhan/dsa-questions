class Solution {
public:
    long long wonderfulSubstrings(string& word) {
        long long ans=0;
        int mask=0;
        int n=word.size();
        vector<int> count(1024, 0);
        count[0]=1;
        
        for(int i=0;i<n;i++)
        {
            mask ^= (1<<(word[i]-'a'));
            ans += count[mask];
            
            for(int j=0;j<10;j++)
            {
                ans += count[mask^(1<<j)];
            }
            
            count[mask]++;
        }
        
        return ans;
    }
};