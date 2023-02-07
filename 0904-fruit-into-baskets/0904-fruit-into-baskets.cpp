class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n==0) return 0;
        
        int i=0,j=0,c=0, ans=1;
        map<int,int> m;
        while(j!=n)
        {
            m[fruits[j]]++;
            if(m[fruits[j]]==1) c++;
            if(c<=2)
            {
                ans = max(ans,j-i+1);
            }
            else if(c==3)
            {
                while(c==3)
                {
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0) c--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};