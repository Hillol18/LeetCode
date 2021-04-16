class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        int n = sequence.size();
        int m = word.size();
        string temp = word;
        int low= 0,high = n/m;

        while(low<=high){
            int mid = (low+high)/2;
            string temp = "";

            for(int j=0;j<mid;j++){
                temp+=word;
            }

            if(sequence.find(temp) == -1) {
                high=mid-1;
            }
            else{
                ans = mid;
                low = mid+1;
            }
        }

        return ans;
    }
};
