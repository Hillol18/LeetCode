/*
    0 up
    1 right
    2 down
    3 left
    
   
     |
     |
    
            
     _ _ _ _ _
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
        if(c == 'L'){
            d--;
        }
        else {
            d++;
        }
        
        if(d>3) d = 0;
        if(d<0) d = 3;
        return d;
    }
    
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int dir=0;
        int len = instructions.size();
        int k = 4;
        while(k--){            
            for(int i=0;i<len;i++){
                if(instructions[i] == 'G'){
                    move(x, y, dir);
                }
                else{
                    dir = nextDir(dir, instructions[i]);
                }
            }            
        }
        return x == 0 && y == 0;
    }
};