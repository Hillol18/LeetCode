class SummaryRanges {
public:
    /** Initialize your data structure here. */
    set<vector<int>>st;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        
        int low = val;
        int high = val;
        
        auto it = st.lower_bound({val, val});        
        
        if(it != st.end()){
            if((*it)[0]<=(high+1)) {
                high = max(high, (*it)[1]);
                it = st.erase(it);
            }
        }
        
        if(st.begin() != it) it--;
        
        if(it != st.end() &&((*it)[0]) <= (low-1) && (low-1) <= ((*it)[1])){
            low = min(low, (*it)[0]);
            high = max(high, (*it)[1]);
            st.erase(it);
        }
        
        st.insert({low, high});
        
    }
    
    vector<vector<int>> getIntervals() {
        auto it = st.begin();
        vector<vector<int>> ans;
        while(it != st.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};