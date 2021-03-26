
class Solution {
public:

    double findMedian(vector<int>& a, vector<int> &b){
        int low=0,high=a.size();
        int n = a.size() + b.size();
        int midIndex = n/2 + n %2;
        double ans = 0.0;
        while(low<=high){
            //cout<<low<<" "<<high<<endl;
            int mid = (low+high)/2;

            int a_left = INT_MIN;
            int a_right = INT_MAX;
            if(mid>0){
                a_left = a[mid-1];
            }

            if(mid<a.size()){
                a_right = a[mid];
            }

            int rest = midIndex-mid;

            int b_left = INT_MIN;
            int b_right = INT_MAX;

            if(rest>0) b_left = b[rest-1];
            if(rest<b.size()) b_right = b[rest];
            ///cout<<a_left<<" "<<a_right<<endl;
            //cout<<b_left<<" "<<b_right<<endl;
            if(a_left<=b_right && b_left <=a_right){
                if(n%2==0){
                   double sum = max(a_left,b_left) + min(a_right,b_right);
                    ans = sum/2.00;
                }
                else{
                    ans = max(a_left,b_left);
                }
                return ans;
            }
            else if(a_left > b_right) high=mid-1;
            else low=mid+1;

        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double ans = 0.00;
        if(m<n){
            ans = findMedian(nums1, nums2);
        }
        else{
            ans = findMedian(nums2, nums1);
        }
        return ans;
    }
};
