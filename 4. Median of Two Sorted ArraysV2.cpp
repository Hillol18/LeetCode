class Solution {
public:
    
    double findMedian(vector<int>& a, vector<int> &b){
        int low=0,high=a.size();
        int m = b.size();
        int n = a.size();
        int midIndex = (n+m)/2 + (n+m) % 2;
        double ans = 0.0;
        while(low<=high){
            int mid = (low + high)/2;
            int rest = midIndex - mid;
            
            int aleft = INT_MIN, aright = INT_MAX;
            int bleft = INT_MIN, bright = INT_MAX;
            if(mid) aleft = a[mid-1];
            if(mid < n) aright = a[mid];
            
            if(rest) bleft = b[rest-1];
            if(rest < m) bright = b[rest];
            
            //cout<<aleft<<" "<<aright<<" "<<bleft<<" "<<bright<<endl;
            if(aleft > bright) high = mid-1;
            else if(rest > b.size() || bleft > aright ) low = mid+1;
            else{
                if((m+n)%2){
                    return max(aleft, bleft);
                }
                else{
                    return double(max(aleft , bleft) + min(aright,bright)) /2.00;
                }
            }
            
        }
        return 0.0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double ans = 0.00;
        if(m<=n){
            ans = findMedian(nums1, nums2);
        }
        else{
            ans = findMedian(nums2, nums1);
        }
        return ans;
    }
};