class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while(num){
            if(num & 1){
                num--;
                cnt++;
            }
            else {
                cnt++;
                num/=2;
            }
        }
        return cnt;
    }
};
