

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int front=0;
        int cur = 1;
        while(front<nums.size() && cur<nums.size() &&  nums[front]<=nums[cur])
        {
            front++;
            cur++;

        }

        if(cur==nums.size()) return 0;

        for(int i=cur;i<nums.size() && front>=0;i++){
            while(front >=0 && nums[front] > nums[i]) front--;
        }

        int last = nums.size()-1;
        cur = last-1;
        while(cur >= 0 && nums[cur] <= nums[last]){
            cur--;
            last--;
        }

        for(int i=cur;i>=0 && last<nums.size();i--){
            while(last <nums.size() && nums[last] < nums[i]) last++;
        }

       return nums.size()-(front+1)-(nums.size() - last);
    }
};
