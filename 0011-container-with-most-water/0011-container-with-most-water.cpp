class Solution {
public:
    int maxArea(vector<int>& height) {
        int j=height.size()-1,i=0;
        int area=0;
        while(i<j)
        {
            area=max(area,min(height[i],height[j])*(j-i));
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return area;
    }
};