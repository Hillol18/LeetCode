/*

2 3 41 51
1 1 2

4
3

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int l=0, r=nums1.size();
        int midIndex=(nums1.size()+nums2.size()+1)/2;
        r=min(r, midIndex);
        int lf,rf,ls,rs;
        double ans=0.0;
        bool odd=((nums1.size()+nums2.size())%2);
        cout<<odd<<endl;

        if(nums1.size()==0){
            if(odd){
                ans=nums2[midIndex-1];
            }
            else{
                ans = (nums2[midIndex] +nums2[midIndex-1])/2.00;
            }
            return ans;
        }

        if(nums2.size()==0){
            if(odd){
                ans=nums1[midIndex-1];
            }
            else{
                ans = (nums1[midIndex] +nums1[midIndex-1])/2.00;
            }
            return ans;

        }


        while(l<=r){
            int mid = (l+r)/2;

            if(mid==0){
                lf=INT_MIN;
            }
            else{
                lf=nums1[mid-1];
            }

            if(mid>=nums1.size()){
                rf=INT_MAX;
            }
            else {
                rf=nums1[mid];
            }

            int sMid= midIndex-mid;
            //cout<<mid<<" _ "<<sMid<<endl;
            if(sMid > nums2.size()){
                l=mid+1;
                continue;
            }

            if(sMid==0){
                ls=INT_MIN;
            }
            else {
                ls=nums2[sMid-1];
            }

            if(sMid>=nums2.size()){
                rs=INT_MAX;
            }
            else {
                rs=nums2[sMid];
            }
            //cout<<mid<<" "<<lf<<" "<<rf<<" "<<ls<<" "<<rs<<endl;
            if(lf<=rs && ls<=rf){
                if(odd){
                    ans=(max(lf,ls));
                }
                else{
                    ans=(max(lf,ls) + min(rf,rs))/2.0;
                }
                break;
            }

            if(lf>rs ){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;

    }
};
