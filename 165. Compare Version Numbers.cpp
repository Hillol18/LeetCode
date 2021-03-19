class Solution {
public:

    bool isComplete(string &data, int &index){
        if(data.size() == index || data[index] == '.') return true;
        return false;
    }

    int compareVersion(string version1, string version2) {
        int l= version1.size();
        int r= version2.size();
        int i,j;
        i=j=0;

        while(i<l || j<r){
            while(i<l && version1[i] =='0') i++;
            while(j<r && version2[j] =='0') j++;

            int d = 0;

            //cout<<i<<" "<<j<<endl;
            while(i<l && j<r && version1[i]!='.' && version2[j]!='.'){
                if(!d){
                    if(version1[i] < version2[j]){
                        d=-1;
                    }
                    else if(version1[i] > version2[j]){
                        d= 1;
                    }
                }
                i++;
                j++;
            }
            //cout<<i<<" "<<isComplete(version1, i)<<" "<<j<<" "<<isComplete(version2, j)<<" "<<endl;
            if(isComplete(version1, i) && !isComplete(version2, j)) return -1;
            if(!isComplete(version1, i) && isComplete(version2, j)) return 1;

            if(d) return d;

            if(i<l)
            i++;
            if(j<r)
            j++;

        }

        return 0;
    }
};
