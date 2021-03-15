/*
Nafiul
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int f=0;
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                //cout<<f<<" "<<i<<endl;
                if(i>f) reverse(s.begin()+f, s.begin()+i);
                f=i+1;
            }
        }
        if(f<n){
            reverse(s.begin()+f, s.end());
        }
    }
};
