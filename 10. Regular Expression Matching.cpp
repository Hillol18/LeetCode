class Solution {
    /*
    s = "aab"
    p = "cab"
         **
        .*
        c*

         =>26

    */

public:

    bool fun(int i, int j, string &s, vector<pair<char,char>>&pp, vector<vector<int>> &dp ){
        //cout<<i<<" "<<j<<endl;
        if(i==s.size() && j == pp.size()){
            return 1;
        }

        if(i>s.size())
            return 0;
        if(j==pp.size())
            return 0;
        int &ans = dp[i][j];
        if(ans !=-1)
            return ans;
        ans = 0;

        if( (pp[j].first =='.') && (pp[j].second=='*')){
            //cout<<"in"<<endl;
              ans|= fun(i+1, j,s,pp,dp);
              ans|= fun(i+1, j+1,s,pp,dp);

            ans|= fun(i, j+1,s,pp,dp);

        }
        else if(pp[j].second =='*'){
           if(s[i] == pp[j].first){
              ans|= fun(i+1,j+1,s,pp,dp);
              ans|= fun(i+1,j,s,pp,dp);
           }
           ans|= fun(i,j+1,s,pp,dp);
        }
        else if((s[i]==pp[j].first)||('.'==pp[j].first)){
            ans|= fun(i+1,j+1,s,pp,dp);
        }

        return ans;
    }


    bool isMatch(string s, string p) {


        vector<pair<char,char>> pp;
        int size=-1;
        for(int j=0;j<p.size();j++){
            //cout<<p[j]<<endl;
            if(p[j]=='*'){
                //cout<<"dd"<<endl;
                if(size>=0){
                    //cout<<"fff"<<endl;
                    pp[size].second = p[j];
                 }
            }
            else {
                    pp.push_back(make_pair(p[j],'#'));
                    size++;
            }
        }
        vector<vector<int>>dp(s.size()+2, vector<int>(pp.size()+1, -1));
        //cout<<pp[0].first<<pp[0].second<<endl;

       return fun(0,0,s,pp, dp);
    }
};
