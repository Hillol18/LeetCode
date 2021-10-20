/*
9*1
90*2
900*3
9000*4
90000*5
900000*6

6

*/

class Solution {
public:
    int findNthDigit(int n) {
        long long int m = 9;
        long long int d = 1;
        long long int t = 1;
        
        while(n){
            
            long long int total = m*d;
            if(total >= n) break;
            
            t+=m;
            n-= total;
            m*=10L;
            d++;
        }

        int number = (n - 1)/d;
        
        int left = n - number * d;
        //cout<<number+t<< " "<<m<<" "<<d<<" "<<n<<" "<<left<<endl;
       int ans = to_string(number + t)[left-1] - '0';
       return ans; 
    }
};