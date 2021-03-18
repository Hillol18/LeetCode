class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int flag = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            int j = i+1, k= n-1;

            while(j<k){
                int tempSum = nums[i] + nums[j] + nums[k];
                //cout<<tempSum <<" "<<j<<" "<<k<<" "<<sum<<endl;
                if(!flag || abs(target-tempSum) < abs(target-sum)){
                    sum = tempSum;
                    flag = 1;
                }


                if(tempSum<=target){
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return sum;
    }
};
