class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r=matrix.size()-1,c=0;
        if(r<0) return false;

        int col= matrix[0].size();

        while(r>=0 && c<col){
           // cout<<r<<" "<<c<<endl;
            if(target < matrix[r][c]) r--;
            else if(target>matrix[r][c]) c++;
            else return true;
        }
        return false;
    }

};
