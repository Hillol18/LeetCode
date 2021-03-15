/*
I= 1
IV= 4
V= 5
Ix=9
X= 10
XL=40
L= 50
XC=90
C= 100
CD=400
D= 500
CM=900
M= 1000
MCMXCIV

1000+900+
*/
class Solution {
public:
    int romanToInt(string s) {
      unordered_map<string,int> mp;
        mp["I"] = 1;
        mp["IV"]=4;
        mp["V"]=5;
        mp["IX"]=9;
        mp["X"]=10;
        mp["XL"]=40;
        mp["L"]= 50;
        mp["XC"]= 90;
        mp["C"]=100;
        mp["CD"]=400;
        mp["D"]=500;
        mp["CM"]=900;
        mp["M"]=1000;

        int sum = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            auto it=mp.end();
            if((i+1)<n){
                it=mp.find(s.substr(i,2));
            }

            if(it!= mp.end()){
                sum+=it->second;
                i++;
            }
            else{
              //cout<<string(1,s[i])<<" "<<mp[string(1,s[i])]<<endl;
               sum+=mp[string(1,s[i])];
            }


        }
        return sum;
    }
};
