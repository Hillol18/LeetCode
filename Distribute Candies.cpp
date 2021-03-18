class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>st;
        int n = candyType.size();
        for(int i=0;i<n;i++){
            st.insert(candyType[i]);
        }

        n=n/2;

        return n <= st.size()?n: st.size();

    }
};
