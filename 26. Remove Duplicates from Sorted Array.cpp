class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int cur=10005;
        int j=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(cur != nums[i]){
                nums[j]=nums[i];
                j++;
                cur = nums[i];
            }
        }

        return j;
    }
};
