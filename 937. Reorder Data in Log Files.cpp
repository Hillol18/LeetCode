class Solution {
public:


    bool static isDeg(string &s){

        stringstream ss(s);
        string temp;

        ss>>temp;
        ss>>temp;


        return ('0'<= temp[0]) && (temp[0]<='9');
    }

    bool static cmp(string &s1, string &s2){

        bool a1 = isDeg(s1);
        bool a2 = isDeg(s2);

        string a1s= s1.substr(s1.find(' '));

        string a2s = s2.substr(s2.find(' '));

        if(a1s == a2s){
            return (s1.substr(0, s1.find(' ')) < s2.substr(0, s2.find(' ')));
        }
        else return a1s<a2s;


        return false;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<string>l,d;

        for(int i=0;i<logs.size();i++){
            if(isDeg(logs[i])){
                d.push_back(logs[i]);
            }
            else{
                l.push_back(logs[i]);
            }
        }


       sort(l.begin(), l.end(), cmp);
        for(int i=0;i<d.size();i++) l.push_back(d[i]);
        return l;

    }
};
