/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
/*
Nafiul

[
[1,1,1,1,1,0,1,1],
[1,1,1,1,1,0,1,1],
[1,0,1,1,1,1,1,1],
[0,0,0,1,0,0,0,0],
[1,1,1,1,1,1,1,1]]
1
3


*/
class Solution {
public:
    
    pair<int,int> Next(int r, int c, int dir){
        if(dir == 0){
            r--;
        }
        else if(dir == 1){
            c++;
        }
        else if(dir == 2){
            r++;
        }
        else{
            c--;
        }
        return make_pair(r, c);
    }
    
    string getEncData(int r, int c, int dir){
        return to_string(r) + "#" + to_string(c) + "#" + to_string(dir);
    }
    
    void goBack(Robot &robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    
    
    void dfs(int r, int c, int dir, Robot& robot, unordered_set<string> & _ump){
        
        string temp = getEncData(r, c, dir);
        //cout<<temp<<endl;
        _ump.insert(temp);
        robot.clean();
        
        for(int i = 0; i<4; i++){
            int d = (i + dir) % 4;
            auto it = Next(r, c, d);
            
             temp = getEncData(it.first, it.second, d);
            
            if(_ump.find(temp) == _ump.end() &&  robot.move()){
                 dfs(it.first, it.second, d, robot, _ump);
            }
            robot.turnRight();
        }
        goBack(robot);
    }
    
    void cleanRoom(Robot& robot) {
        unordered_set<string> uset;
        dfs(0, 0, 0, robot, uset);
    }
};