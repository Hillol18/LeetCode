class Solution {
public:
    
    void helper(vector<int> &nums, vector<int> &leftMin, vector<int> &leftMax, bool rev = false){
        
        stack<int> stMin, stMax;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(!stMin.empty() && ((!rev && nums[stMin.top()] >= nums[i]) || (rev && nums[stMin.top()] > nums[i]))){
                stMin.pop();
            }
            int idx = -1;
            
            if(!stMin.empty()) idx = stMin.top();
            
            leftMin[i] = i-idx;
            
            stMin.push(i);
            
            while(!stMax.empty() && ((!rev && nums[stMax.top()] < nums[i])||(rev && nums[stMax.top()] <= nums[i]))){
                stMax.pop();
            }
            
            idx = -1;
            
            if(!stMax.empty()) idx = stMax.top();
            
            leftMax[i] = i-idx;
            stMax.push(i);
        }
        
    }
    
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        
        vector<int> leftMin(n);
        vector<int> rightMin(n);
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        helper(nums, leftMin, leftMax);
        
        reverse(nums.begin(), nums.end());
        
        helper(nums, rightMin, rightMax, true);
        reverse(rightMin.begin(), rightMin.end());
        reverse(rightMax.begin(), rightMax.end());
        
        reverse(nums.begin(), nums.end());
        long long mn = 0, mx = 0;
        for(int i = 0; i<n; i++){
            long long cnt = leftMin[i] * rightMin[i];
            long long val = nums[i];
            mn += (long long)(cnt * val);
            
            cnt = leftMax[i] * rightMax[i];
            mx += (long long)(cnt * val);
        }
        
       return mx-mn;
        
    }
};