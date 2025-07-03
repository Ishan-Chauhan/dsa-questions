class Solution {
public:
    char kthCharacter(int k) {
        int c=0;
        int x = k&(k-1);
        if(x==0) return char('a'+log2(k));

        while(k!=0)
        {
            x = k&(k-1);
            if(x==0) return char('a'+c+log2(k));

            x = (int)log2(k);
            k = k%(int)pow(2,x);
            c++;

            cout<<x<<endl;
        }
        return char('a'+c);
    }
};