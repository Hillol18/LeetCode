class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;

        vector<int> b(26,0);
        vector<int>pat(26,0);
        int m = B.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<B[i].size();j++){
                b[B[i][j]-'a']++;
            }

            for(int j=0;j<26;j++){
                pat[j]=max(pat[j], b[j]);
                b[j]=0;
            }
        }
        //for(int i=0;i<26;i++)cout<<b[i]<<endl;
        vector<int>temp(26,0);
        int n = A.size();
        for(int i=0;i<n;i++){

            for(int j=0;j<A[i].size();j++){
                temp[A[i][j]-'a']++;
            }
            bool flag = true;

            for(int j=0;j<26;j++){
                if(temp[j] < pat[j]){
                    flag= false;
                }
                temp[j]=0;
            }

            if(flag) ans.push_back(A[i]);
        }
        return ans;
    }
};
