class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int c=0, i=0;
        int len = flowerbed.size();
        if(len==0) return false;
        
        if(flowerbed[0]==0)
        {
            if(len==1)
            {
                c++;
                if(c==n) return true;
            }
            else if(flowerbed[1]==0)
            {
                flowerbed[0]=1;
                c++;
                if(c==n) return true;
            }
        }
        for(int i=1;i<len-1;i++)
        {
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                c++;
                if(c==n) return true;
            }
        }
        if(flowerbed[len-1]==0 && flowerbed[len-2]==0)
        {
            flowerbed[len-1]=1;
            c++;
            if(c==n) return true;
        }
        // cout<<c<<endl;
        return false;
    }
};