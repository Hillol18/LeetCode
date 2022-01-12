class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n-1];
        
        int ans = -1;
        
        while(low <= high){
            int cnt = 0;
            int mid = (low + high)/2;
            bool flag = false;            
            for(int i = 0; i < n-1; i++){
                
                int l = i+1, h = n-1;
                int c = 0;

                while(l <= h){
                    int m = (l + h)/2;
                    int dif = abs(nums[m] - nums[i]);
                    
                    if(dif == mid) flag = true;
                    if(dif <= mid){
                        c = m;
                        l = m + 1;
                    }
                    else{                        
                        h = m - 1;
                    }
                }
                
                if(c > i)
                cnt += (c- i);
            }
            
            //cout<<" "<<mid<<" "<<cnt<<" "<<flag<<endl;
            if(cnt < k) {
                low = mid + 1;
            }
            else{
                if(flag) ans = mid; 
                high = mid - 1;
            }
            
        }
        return ans;
    }
};