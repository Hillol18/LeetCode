/*

10000
14

10  11    1
100 110   10
1000 1100 100 

13
10 11 

12
100   101    1
1000  1010   10


*/
class Solution {
public:
    
    int findKthNumber(int n, int k) {
        
        int result = 1;
        while(k > 1){
            //cout<<result<<" "<<k<<endl;
            long long p1 = result, p2 = result + 1;
            
            long long cnt = 0;
            
            while(p1 <= n && p1 < p2 && cnt <= k){
                cnt += p2 - p1;
                
                p1 *= 10l;
                p2 *= 10l;
                p2 = min(p2,(long long) n+1);
            }
            
            if(cnt >= k){
                result *= 10;
                k--;
            }
            else{
                result++;
                k -= cnt;
            }
            
        }
        
        return result;
    }
};