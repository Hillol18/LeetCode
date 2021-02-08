/*
    0 up
    1 right
    2 down
    3 left

*/

class Solution {
public:
    void move(int &x,int &y, int &dir){
        if(dir==0){
            y--;
        }
        else if(dir==1){
            x++;
        }
        else if(dir==2){
            y++;
        }
        else{
            x--;
        }
    }

    int nextDir(int d, char c){
        if(c=='L'){
            d--;
        }
        else {
            d++;
        }

        if(d>3) d = 0;
        if(d<0) d=3;
        return d;
    }

    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int dir=0;
        int len = instructions.size();
        unordered_set<string> st;
        int k = 5;
        while(k--){
            int cnt = len;

            for(int i=0;i<len;i++){
                if(instructions[i]=='G'){
                    move(x,y,dir);
                }
                else{
                   dir=nextDir(dir, instructions[i]);
                }

                auto pair= to_string(x)+to_string(y);
                if(st.find(pair) == st.end()){
                    st.insert(pair);
                }
                else cnt--;
            }

            if(cnt==0)
                return true;
        }
        return false;
    }
};
