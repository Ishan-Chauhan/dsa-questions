class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int m=1, n=arr.size();
        int c=0;
        int i = 0;
        while(i<n)
        {
            if(arr[i]!=m)
            {
                c++;
            }
            else i++;
            
            
            if(c==k) return m;
            
            m++;
        }
        m--;
        
        while(c!=k)
        {
            // cout<<m;
            c++;
            m++;
        }
        
        return m;
    }
};