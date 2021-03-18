class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int pre = 0;
        if(nums.size() == 0) return 0;
        int cnt=1;

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]) continue;

            if(nums[i-1] < nums[i] && (pre == 1 || pre ==0)){
              cnt++;
              pre = -1;
            }
            else if(nums[i-1] > nums[i] && (pre==-1 || pre==0)){
                cnt++;
                pre =1;
            }
        }
        return cnt;
    }
};
