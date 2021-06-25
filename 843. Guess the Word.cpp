/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    
    int getMatch(string w, string w2){
        int cnt = 0;
        for(int i=0;i<6;i++){
            cnt += (w[i] == w2[i]);
        }
        return cnt;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_set<string> st;
        
        for(auto word: wordlist){
            st.insert(word);
        }
        int cnt = 10;
        while(cnt--){
            auto it = st.begin();
            if(it == st.end()) break;
            string base = *it;
            st.erase(it);
            int match = master.guess(base);
            //cout<<match<<endl;
            it = st.begin();
            
            while(it != st.end()){
                
                int c = getMatch(*it, base);
                string w = *it;
                it++;
                if(match != c){
                    st.erase(w);
                }
            }   
        }
    }
};