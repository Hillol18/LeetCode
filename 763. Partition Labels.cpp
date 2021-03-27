class Solution {
public:


    vector<int> partitionLabels(string S) {
        vector<int> frequency(26,0);

        int n = S.size();
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            frequency[S[i]-'a']++;
        }


        int bit=0;
        for(int i=0;i<n;i++){
           int idx = S[i]-'a';
            bit |= 1<<(idx);
            cnt++;
           frequency[idx]--;

            if(frequency[idx] == 0){
               bit = bit & (bit^(1<<idx));
               if(bit==0){
                   ans.push_back(cnt);
                   cnt = 0;
               }
            }

        }
        return ans;
    }
};
