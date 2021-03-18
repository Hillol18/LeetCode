/*
0 0 0 0 0 0  0 0 0

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =  nums.size();

        vector<int> temp(3);

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){

            if(i>0 && nums[i] == nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum = nums[j]+ nums[k] + nums[i];
                //cout<<i<<": "<<j<<" "<<k<<" "<<nums[i]<<endl;
                if(sum == 0){
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];


                    ans.push_back(temp);

                    while(j<k && temp[1] == nums[j]) j++;

                }

                else if(sum > 0){
                    k--;
                }
                else
                    j++;
            }
        }
        return ans;
    }
};
