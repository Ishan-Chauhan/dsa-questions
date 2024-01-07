class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closeX, closeY;
        
        if(xCenter>x2) closeX=x2;
        else if(xCenter<x1) closeX=x1;
        else closeX=xCenter;
        
        if(yCenter>y2) closeY=y2;
        else if(yCenter<y1) closeY=y1;
        else closeY=yCenter;
        
        return pow((closeX-xCenter),2) + pow((closeY-yCenter),2) <= radius*radius;
    }
};