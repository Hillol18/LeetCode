class Solution {
public:

    bool find(int low, int high, vector<int>&data, int &target){
        if(high < low)
            return false;
        int mid=(low+high)/2;
        if(data[mid] == target) return true;

        bool ret = false;
        if(data[mid]<target){
            ret |=find(mid+1, high, data,target);
        }
        else{
            ret |=find(low,mid-1, data, target);
        }
        return ret;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return 0;

        int low= 0;
        int high = n-1;
        if(nums[low] == target) return true;
        int pivot = 0;
        int l=low,h=high;

        while(low<=high && nums[low] == nums[high])
            high--;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[0]<=nums[mid] && nums[mid] >= nums[l]){
                pivot = mid;
                low=mid+1;
            }
            else{
                high = mid-1;
            }

        }
        //cout<<pivot<<endl;
        bool ans;
        if(nums[0]<=target && target<= nums[pivot]){
          ans= find(l,pivot, nums, target);
        }
        else{
          ans= find(pivot+1,h, nums, target);
        }
      return ans;
    }
};
