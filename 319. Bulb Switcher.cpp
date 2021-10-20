/*

number of odd divisor item within this range
all perfect square number in this range


1 3 4 9 16

*/
class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        
        if(n <= 2) return 1;
        
        return sqrt(n);
    }
};