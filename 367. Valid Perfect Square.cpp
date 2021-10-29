class Solution {
public:
    bool isPerfectSquare(int num) {
            int low = 1, high = num / 2;
        if(num == 1) return true;
        while(low <= high){
            long mid = (low + high)/ 2;
            
            if(mid * mid == num){
                return true;
            }
            else if(mid * mid  < num){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return false;
    }
};