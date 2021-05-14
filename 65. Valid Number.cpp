class Solution {
public:

    bool isEchar(char ch){
        return (ch == 'E' || ch == 'e');
    }


    bool isNumber(string s) {

        bool ans = true;
        int i=0, j = s.size();
        j--;
        while(i<=j && s[i] == ' '){
            i++;
        }

        while(j>=i && s[j] == ' '){
            j--;
        }

        if(s[i] == '+' || s[i] == '-') i++;

        if(i>j || (i==j && (s[i] == '.'))) ans = false;

        int epos = -2;
        int dot = -2;
        int dig = -2;
        while(i<=j && ans){

                if(s[i] == '+' || s[i] == '-'){
                    if(i == (epos+1) && i<j && isdigit(s[i+1])){
                        i++;
                    }
                    else {
                        ans = false;
                    }
                }
                else if(isEchar(s[i])){

                    if(epos>=0 || dig< 0) ans=false;
                    if(!(i && i<j)) ans = false;
                    epos = i;
                }
                else if(s[i] == '.'){
                    if(dot >= 0) ans = false;
                    if(epos>=0 && epos < i) ans =false;
                    dot=i;
                }
                else {
                    if(!isdigit(s[i])) {
                        ans = false;
                    }
                    else dig=i;
                }

            i++;
        }

        return ans;
    }
};
