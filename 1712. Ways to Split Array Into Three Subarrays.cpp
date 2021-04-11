class Solution {
public:
    int help(int index, vector<int>& nums, bool isLeft){

        int leftSum = nums[index];
        int l = index+1;
        int n = nums.size()-1;
        int r = n-1;


        int ans = -1;

        while(l<=r){
            //cout<<l<<" -- "<<r<<endl;
            int mid = (l+r)/2;
            int midSum = nums[mid]-leftSum;
            int rightSum = nums[n] - nums[mid];
            //cout<<leftSum<<" "<<midSum<<" "<<rightSum<<endl;
            if(leftSum <= midSum && midSum <= rightSum){
                ans = mid;
                if(isLeft){
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            else if(leftSum > midSum){
                l=mid+1;

            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }

    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
          nums[i]+=nums[i-1];
        }

        int ans = 0;
        int md = 1e9 +7;
        for(int i=0;i<n-1;i++){
           int left = help(i,nums,1);
           int right = help(i,nums,0);

           if(left !=-1 && right != -1){
               ans +=(right-left+1);
               ans %=md;
           }
        }

        return ans;
    }
};
