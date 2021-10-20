class Solution {
public:
    
    bool isOverlap(vector<int>& rec1, vector<int>& rec2){
        int x1 = rec1[0];
        int x2 = rec1[2];
        int y1 = rec1[1];
        int y2 = rec1[3];
        
        if(x1 < rec2[2] && rec2[0] < x2 && y1 < rec2[3] && rec2[1] < y2) return true;
        return false;
    }
    
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        return isOverlap(rec1, rec2); 
    }
};