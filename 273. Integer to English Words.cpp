
/*


990000
2101100
one two three

*/

class Solution {
public:

    string toWord(int num){
        vector<string> str = {"", "One","Two","Three","Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven","Twelve","Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen","Nineteen","Twenty", "Thirty","Forty","Fifty","Sixty", "Seventy", "Eighty","Ninety"};

        string ans = "";
        if(num>=1000000000){
            ans = toWord(num/1000000000) + " Billion " + toWord(num%1000000000);
        }
        else if(num>=1000000){
            ans = toWord(num/1000000) + " Million " + toWord(num%1000000);
        }
        else if(num>=1000){
            ans = toWord(num/1000) + " Thousand " + toWord(num%1000);
        }
        else if(num>=100){
            ans = toWord(num/100) + " Hundred " + toWord(num%100);
        }
        else if(num>20){
            ans = str[num/10 - 2 + 20]+" " + toWord(num%10);
        }
        else ans = str[num];

        if(ans.size() && ans[ans.size()-1] == ' '){
            ans.pop_back();
        }

        return ans;
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";
        string ans = toWord(num);

        //if(ans.size() && ans[ans.size()-1]==' ' )
        return ans;

    }
};
