class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();

        int l=0,r=n-1,mid;

        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(arr[mid]==target) return mid;
            if(l==r) return -1;

            if(arr[mid+1]<=arr[r])
            {
                if(target>=arr[mid+1] && target<=arr[r]) l=mid+1;
                else r=mid-1;
            }
            else
            {
                if(target>=arr[l] && target<=arr[mid-1]) r=mid-1;
                else l=mid+1;
            }
        }
        return -1;
    }
};