class Solution {
public:
    bool check(vector<int> &cnt1, vector<int> &cnt2){
        for(int i = 0; i < 26; i++){
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        int n = s2.size();
        vector< int > cnt2(26, 0), cnt1(26, 0);
        for(int i = 0; i < len; i++){
            cnt1[s1[i] - 'a']++;
        }

        int i = 0, j = 0;


        while(j < n){
            cnt2[s2[j] - 'a']++;

            if(( j-i+1 ) > len){
                cnt2[s2[i] - 'a']--;
                i++;
            }

            if(check(cnt1, cnt2)) return true;
            j++;
        }

      return false;
    }
};
