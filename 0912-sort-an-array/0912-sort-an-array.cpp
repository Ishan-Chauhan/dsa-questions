class Solution {
public:
    void heapify(int i, int n, vector<int>& v)
    {
        int c1 = 2*i+1;
        int c2 = 2*i+2;
        int lar = i;
        if(c1<n && v[c1]<v[lar]) lar = c1;
        if(c2<n && v[c2]<v[lar]) lar = c2;
        
        if(lar!=i)
        {
            swap(v[i],v[lar]);
            heapify(lar,n,v);
        }
    }
    void buildheap(vector<int>& v, int n)
    {
        for(int i=n/2;i>=0;i--)
        {
            heapify(i,n,v);
        }
    }
    int extractmax(vector<int>& v, int n)
    {
        int ans = v[0];
        swap(v[0],v[n-1]);
        n--;
        heapify(0,n,v);
        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int m = n;
        vector<int> ans(n);
        buildheap(nums, n);
        for(int i=0;i<n;i++)
        {
            ans[i] = extractmax(nums,m);
            m--;
        }
        return ans;
    }
};