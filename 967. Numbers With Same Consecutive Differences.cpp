class Solution {
public:

    void fun(int pos, int pre, int number,vector<int> &ans, int &k, int &n){

        if(n==pos){
            ans.push_back(number);
            return;
        }

        for(int i=(pos==0);i<10 && pre==-1;i++){
            fun(pos+1, i, i, ans, k, n);
        }

        if(pre>=0){
            if(pre-k >=0){
                fun(pos+1, pre-k,number*10 + pre-k, ans, k, n);
            }
            if((pre+k)<10 && k>0){
                fun(pos+1, pre+k,number*10 + pre+k, ans, k, n);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        fun(0,-1,0,ans, k,n);
        return ans;
    }
};
