class Solution {
public:


    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int pos=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]> nums[i]){
                cnt++;
                pos=i;
            }
        }

        if(cnt>1) return false;

        bool ans = false;

        if(cnt == 1){
            if(pos==(n-1) || nums[pos-1] <= nums[pos+1]) ans= true;
            else if(pos==1 || nums[pos-2]<= nums[pos]) ans = true;
        }
        else
        ans = true;


        return ans;
    }
};
