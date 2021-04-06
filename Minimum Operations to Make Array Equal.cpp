class Solution {
public:
    int minOperations(int n) {
        int mid = (n-1);
        int mx = (mid/2)*2 +1;
            mx += (mid%2);


        int cur = 1;
        int ans = 0;

        while(cur<mx){
            ans+=(mx-cur);
            cur+=2;
        }
        return ans;
    }
};
