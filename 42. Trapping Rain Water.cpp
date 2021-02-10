/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        stack<int> stk;
        int len = height.size();
        int h=0;
        int sum = 0;
        for(int i=0;i<len;i++){  
            
            if(!stk.empty() && height[stk.top()] <= height[i]){
                int hh = 0;
                while(!stk.empty() && height[stk.top()] <= height[i]){
                    //sum +=(height[stk.top()] -h) * (i-stk.top()-1);
                   int h=height[stk.top()];
                    stk.pop();
                    
                    if(!stk.empty()){
                   //     cout<<min(height[i],height[stk.top()])<<endl;
                     int mxArea =  (min(height[i],height[stk.top()])-hh) * (i-stk.top()-1);
                     int mnArea =  (h-hh) * (i-stk.top()-1);
                     sum+=(mxArea-mnArea);
                     hh=h;
                        
                    }
                }
            }

            stk.push(i);
        }
        return sum;
    }
};
