class Solution {
public:
    int sol(vector<int>&arr,int target,int d){
        
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            
            int mid = low + (high - low)/2;
            if(abs(arr[mid] - target) <= d){
                return 0;
            }
            else if(arr[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        return 1;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        
        sort(arr2.begin(), arr2.end());
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans += sol(arr2, arr1[i], d);
        }
        
        return ans;
    }
};