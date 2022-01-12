class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            
            int left = i - k -1;
            if(left >= 0) {
                auto it = st.find(nums[left]);
                st.erase(it);
            }
            
            if(st.find(nums[i]) != st.end()) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};