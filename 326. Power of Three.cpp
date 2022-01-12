class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 ) return false;
      
        int value = pow(3, 19);
        return value % n == 0;
    }
};