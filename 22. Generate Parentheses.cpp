class Solution {
public:


    void help(int pos,int b,string temp, vector<string> &d){
        if(pos==0)
        {
            if(b==0){
                d.push_back(temp);
            }
            return;
        }


        help(pos-1, b+1, temp+'(',d);
        if(b)
        help(pos-1, b-1, temp+')',d);
    }


    vector<string> generateParenthesis(int n) {
       vector<string> ans;
        help(n*2,0,"",ans);
        return ans;
    }
};
