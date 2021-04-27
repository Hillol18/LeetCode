class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();
        if(n==0) return;

        int i=n-2;
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        int j=0;
        if(i>=0){
            j=i+1;
            while(j<n && nums[j] > nums[i]){
                j++;
            }
            j--;
            swap(nums[i], nums[j]);
            i++;
        }
        else i=0;

        reverse(nums.begin()+i, nums.end());
    }
};
