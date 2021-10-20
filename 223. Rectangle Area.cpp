class Solution {
public:
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int area1 = abs(ax1-ax2) * abs(ay1-ay2);
        int area2 = abs(bx1-bx2) * abs(by1-by2);
        int total = area1 + area2;
        int len1 = abs(min(ax2, bx2) - max(ax1, bx1));
        int len2 = abs(max(ay1, by1) - min(ay2, by2));
        int common = len1 * len2;
        
        if(ax2<bx1 || bx2 < ax1 || ay1 > by2 || ay2 < by1) common = 0;
        
        return total - common;
    }
};