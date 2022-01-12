/*

[1,5,9,1,5,9]
2
3

1
5
9


*/

class Solution {
public:
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        multiset<int> st;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
            int left = i - k -1;
    
            if(left >=0){
    
                auto it =  st.find(nums[left]);
                st.erase(it);
            }
            
            auto it = st.find(nums[i]);
            
            if(it != st.begin()){
                it--;  
                
                if((long long)nums[i] - (long long)*it <= t) return true;
                it++;
            } 
            
            it++;
            if(it != st.end()){
               if((long long)*it - (long long)nums[i]  <= t) return true;
            }
        }
        
        
        return false;
    }
};