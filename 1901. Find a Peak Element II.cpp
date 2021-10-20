class Solution {
public:
    
    int getMaxIndex(vector<int> &arr){
        int index = 0;
        int value = arr[0];
        for(int i = 0; i < arr.size(); i++){
            if(value < arr[i]){
                value = arr[i];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        vector<int> ans;
        
        int low = 0, high = mat.size()-1;
        
        while(low < high){
            
            int mid = (low+high)/2;
            
            
            int idx = getMaxIndex(mat[mid]);
            
            if( mat[mid+1][idx] > mat[mid][idx]){
                low = mid+1;
            }
            else high = mid;
        }
        
        int col = getMaxIndex(mat[low]);
        
        ans = {low, col};
        return ans;
    }
};