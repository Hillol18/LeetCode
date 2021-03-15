class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        deque<int> pre_qu;

        deque<int>pre;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
               pre_qu.push_back(i);
            }
            else if(s[i]==')'){
                if(!pre_qu.empty()){
                    pre_qu.pop_back();
                }
                else{
                    pre.push_back(i);
                }
            }
        }

        for(int i=0;i<s.size();i++){
            if(!pre_qu.empty() && pre_qu.front()==i){
                pre_qu.pop_front();
            }
            else if(!pre.empty() && pre.front() == i){
                pre.pop_front();
            }
            else{
                ans+=s[i];
            }
        }

        return ans;
    }
};
