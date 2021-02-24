class Solution {
public:

    string findLongestWord(string s, vector<string>& d) {
        int r=-1;
        string w="";
        int len = d.size();
        for(int i=0;i<len;i++){
            string cur = d[i];

            int k=0,l=0;

            while(k<s.size()&&l<=cur.size()){
                if(s[k] == cur[l]) {
                    k++;
                    l++;
                }
                else{
                    k++;
                }
            }

            if(l==cur.size()){
                int cnt = s.size()-l;
                //cout<<d[i]<<" "<<cnt<<endl;
                if(r==-1 || r > cnt){
                    r=cnt;
                    w=d[i];
                }
                else if(r==cnt){
                    if(w.size() && w > d[i]) w=d[i];
                }
            }

        }
        return w;
    }
};
