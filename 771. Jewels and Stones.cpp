class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> u_st;
        
        for(auto ch: jewels){
            u_st.insert(ch);
        }
        
        int  cnt = 0;
        for(auto ch: stones){
            if(u_st.find(ch) != u_st.end()){
                cnt++;
            }
        }
        return cnt;
    }
};