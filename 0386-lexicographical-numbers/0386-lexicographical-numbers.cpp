class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n==1) return {1};
        vector<int> v;
        int c=1;

        for(int i=0;i<n;i++)
        {
            v.push_back(c);
            if(c*10<=n) c*=10;
            else
            {
                while(c%10==9 || c>=n) c/=10;
                c++;
            }
        }

        return v;
    }
};