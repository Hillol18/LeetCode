
/*
000101 = 5
111010

111010 = ~5
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int p = log2(n)+1;
       return ((1 << p) - 1) & ~n;
    }
};