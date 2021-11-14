class Solution {
public:
    
    bool isValid(int startTime, vector<int> &arr){
        for(auto item: arr){
            startTime += item;
            
            if(startTime <= 0) return false;
        }
        return true;
    }
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums){
            sum += abs(it);
        }
        
        int low =1, high = sum;
        int ans = sum;
        while(low <= high){
            
            int mid = (low + high) /2;
            //cout<<mid<<endl;
            if(isValid(mid, nums)){
                ans = mid;
                high = mid - 1;
                
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};