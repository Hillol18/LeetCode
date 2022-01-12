/*
8 10 5 =? 50
40 4 8 12 3
4
10 20 30 40
8
5 10 15 20

*/

class Solution {
public:
    long long md = 1000000007;
    int nthMagicalNumber(int n, int a, int b) {
        long long int low = 1,  high = (long long)max(a,b)*(long long)n;
        long long aa = a, bb=b;
        long long ans = 0;
        long long gcd = __gcd(aa, bb);
        long long lcm = ((aa*bb)/gcd);
        
        while(low<=high){
           
            long long mid = (long long)(low + high)/2ll;
            long long na = mid/aa;
            long long nb = mid/bb;
            
            long long cm = mid / lcm;
            
            if((na+nb-cm)  < n){
                low = mid+1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        if(ans >= md)
            ans %= md;
        return ans;
    }
};