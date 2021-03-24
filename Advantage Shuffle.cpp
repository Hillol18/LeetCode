class Solution {
public:

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> u_st;
        int n = A.size();

        sort(A.begin(), A.end());
        vector<pair<int,int>> d(n);

        for(int i=0;i<n;i++){
            d[i]=make_pair(B[i],i);
        }

        sort(d.begin(), d.end());
        int m = B.size();
        vector<int> ans(n);
        int low=0,high=n-1;
        for(int i=m-1;i>=0;i--){
            if(d[i].first>=A[high]){
                //ans.push_back(A[low]);
                ans[d[i].second] = A[low];
                low++;
            }
            else{
                ans[d[i].second] = A[high];
                //ans.push_back(A[high]);
                high--;
            }
        }

        return ans;
    }
};
