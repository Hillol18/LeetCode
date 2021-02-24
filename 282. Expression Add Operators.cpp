class Solution {
public:

    void fun(int pos, string temp, long long int sum, long long int pre, string &num, int &target, vector<string> &ans){

        //cout<<temp<<endl;


        if(pos==num.size())
        {
            ///cout<<temp<<" "<<sum<<endl;
            if(sum==target){
                ans.push_back(temp);
            }

            return;
        }

        if (!pos){
            string tmp = "";
            long long int value =0;
            for(int i=0;i<num.size();i++){
                if(i== pos+1 && value==0) break;
                tmp+=num[i];
                value = value*10L + num[i]-'0';
                fun(i+1, tmp, value,value,num, target, ans);
            }
        }
        else{
            string tmp = "";
            long long int value=0;

            for(int i=pos;i<num.size();i++){
                if(i==pos+1 && value==0) break;
                tmp += num[i];
                value = value*10 + num[i]-'0';

                fun(i+1, temp + "+" + tmp, sum + value,value, num, target, ans);

                fun(i+1, temp + "-" + tmp, sum - value,-1*value, num, target, ans);

                fun(i+1, temp + "*" + tmp, (sum-pre)+ pre * value, pre * value, num, target, ans);

            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        fun(0,"",0,0,num, target, ans);
        return ans;
    }
};
