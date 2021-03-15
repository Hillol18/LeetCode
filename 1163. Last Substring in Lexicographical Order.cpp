class Solution {
public:

    string lastSubstring(string s) {

        int n = s.size();

        int p1=0,p2=1,k=0;
        int i=0;
        while((p1+k)<n && (p2+k)<n){
            //cout<<p1<<" "<<p2<<" "<<k<<endl;
            if(s[p1+k]== s[p2+k]){
                k++;
            }
            else if(s[p1+k]<s[p2+k]){
                int temp=p2;
                p2=max(p1+k+1, p2+1);
                p1=temp;
                k=0;
            }
            else {
                p2=max(p2+k+1,p1+1);
                k=0;
            }
        }

       return s.substr(p1);
    }
};
