class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.size();
        int m = num2.size();
        vector<int> temp(n+m,0);
        string ans(n+m, '0');

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int cur = i+j;
                int next = i+j+1;

                temp[cur]= temp[cur]+ (mul%10);
                temp[next]= temp[next]+ (mul/10);
            }
        }
        int carry=0;
        for(int i=0;i<ans.size();i++){
            int sum = temp[i] + carry;
            //cout<<sum<<" ";
            ans[i]=((sum%10)+ '0');
            carry = sum/10;
        }
        //cout<<endl;

        reverse(ans.begin(), ans.end());
        int i=0;
        while(i<ans.size() &&  ans[i]=='0') i++;

        if(i==ans.size()) return "0";
        ans = ans.substr(i);
        return ans;
    }
};
