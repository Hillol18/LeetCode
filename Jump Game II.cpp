class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        int i=0;
        int cnt = 0;
        n--;
        int cover = 0;
        while(cover<n){
            cover = i+nums[i];
            cnt++;
            int mx = 0;
            int idx=0;
            for(int j=i;j<=min(cover,n);j++){
                if(mx<=(j+nums[j])){
                    mx=j+nums[j];
                    i=j;
                }
            }

        }
        return cnt;
    }
};
