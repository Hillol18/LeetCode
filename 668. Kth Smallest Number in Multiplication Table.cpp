class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = n*m, ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            int cnt = 0;
            int value = -1;
            for(int i = 1; i <= m; i++){
                int d = mid/i;
                cnt += min(d, n);
                if(d*i == mid){
                    value = mid;
                }
            }
            
            if(cnt < k){
                low = mid+1;
            }
            else{
                if(value != -1) 
                    ans = value;
                high = mid-1;
            }
        }
        return ans;
    }
};