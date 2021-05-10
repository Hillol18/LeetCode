class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int sum=0;
        int n = nums.size();
        vector<int> frequency(n+1);
        for(int i=0;i<n;i++){
            if(nums[i]%2)sum++;
            frequency[sum]+=1;
        }
        frequency[0]++;
        int ans= 0;
        cout<<sum<<endl;
        for(int i=k;i<=sum;i++){
            ans+=(frequency[i-k] * frequency[i] );
        }
        return  ans;
    }
};
