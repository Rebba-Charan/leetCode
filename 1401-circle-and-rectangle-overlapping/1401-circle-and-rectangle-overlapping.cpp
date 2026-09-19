class Solution {
public:
    double distance(int xCenter,int yCenter,int x1,int y1)
    {
        return (((xCenter-x1)*(xCenter-x1)) + ((yCenter-y1)*(yCenter-y1)));
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter > x1 && xCenter <x2 && yCenter > y1 && yCenter <y2 ) return true;
        double r = (radius*radius);
        for(int j = y1;j<=y2;j++)
        {
            if(distance(xCenter,yCenter,x1,j) <=r) return 1;
        }
        for(int j = x1;j<=x2;j++)
        {
            if(distance(xCenter,yCenter,j,y1) <=r) return 1;
        }
        for(int j = y1;j<=y2;j++)
        {
            if(distance(xCenter,yCenter,x2,j) <=r) return 1;
        }
        for(int j = x1;j<=x2;j++)
        {
            if(distance(xCenter,yCenter,j,y2) <=r) return 1;
        }
        return 0;
    }
};