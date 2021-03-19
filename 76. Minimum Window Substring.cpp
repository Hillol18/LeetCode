class Solution {
public:

    int getIndex(char c){
        int index = -1;
        if('a' <= c && c<='z'){
                index = c-'a';
            }
            else{
                index = c-'A' + 26;

            }
        return index;
    }
    string minWindow(string s, string t) {
     vector<int> ft(52);

        int cnt = 0;

        for(int i=0;i<t.size();i++){

            int x= getIndex(t[i]);
            ft[x]++;

        }

        for(int i=0;i<52;i++){
            if(ft[i]>0) cnt++;
        }



        vector<int> fs(52);

        int p1=0, p2=0;

        int n = s.size();
        int ans = INT_MAX;
        int ind = 0;

        int j = 0;
        for(int i=0;i<n;i++){
            //cout<<j<<" "<<i<<" "<<cnt<<endl;

            int x = getIndex(s[i]);
                fs[x]++;
                if(fs[x] == ft[x] && ft[x]) cnt--;

            while(cnt == 0 && j<=i){

                if(ans > (i-j+1)){
                    ans = i-j+1;
                    ind = j;
                }
                int x = getIndex(s[j]);

                fs[x]--;
                if(ft[x] > 0  && (fs[x]+1) == ft[x]) cnt++;
                j++;
            }

        }

        return (ans == INT_MAX ? "" : s.substr(ind, ans));
    }
};
