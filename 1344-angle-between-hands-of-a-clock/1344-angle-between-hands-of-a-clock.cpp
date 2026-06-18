class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=0;
        double y=0;
        if(hour<12) x= hour*30 + 0.5*minutes;
        if(hour==12) x= 0.5*minutes;
        y= 6*minutes;
        return min(abs(y-x), 360.0 - abs(y-x));


    }
};