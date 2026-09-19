class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi,yi;

        // Shortcut of if else
        // xi = clamp(xCenter,x1,x2);
        // yi = clamp(yCenter,y1,y2);

        // To find xi
        if(xCenter < x1){
            xi = x1;
        }
        else if(xCenter > x2){
            xi = x2;
        }
        else{
            xi = xCenter;
        }

        // TO find yi
        if(yCenter < y1){
            yi = y1;
        }
        else if(yCenter > y2){
            yi = y2;
        }
        else{
            yi = yCenter;
        }

        // (xi,yi) ----- (xCenter,yCenter)
        int d = sqrt((xi-xCenter)*(xi-xCenter) + (yi-yCenter)*(yi-yCenter));

        return d <= radius;
    }
};