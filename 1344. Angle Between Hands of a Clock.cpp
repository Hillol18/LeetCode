class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrMove = (360.00 / double(12*60)) * (double)(hour*60 + minutes);
        double minutesMove = (360.00 / double(60)) * (double)minutes;
        double degree = fabs(hrMove - minutesMove);
        degree = min(degree, 360.00 - degree);
                              
        return degree;
    }
};