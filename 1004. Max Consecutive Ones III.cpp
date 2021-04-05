class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int cnt=0;
        int low=0;
        int n = A.size();
        for(int i=0;i<n;i++){
            if(A[i]) cnt++;

            while(low<i && (cnt+K)<(i- low + 1)){
                if(A[low])cnt--;
                low++;
            }
            ans= max(ans, min(cnt+K, i- low + 1));
        }
        return ans;
    }
};
