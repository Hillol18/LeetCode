class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int sz = A.size();
        int mx=INT_MIN;

        for(int i=1;i<sz;i++){
                if(mx>A[i]) return false;
            mx=max(mx, A[i-1]);
        }

        return true;
    }
};
