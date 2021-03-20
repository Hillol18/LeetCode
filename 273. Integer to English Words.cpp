class Solution {
public:
    vector<string> spelling{"", "One","Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven","Twelve", "Thirteen", "Fourteen","Fifteen", "Sixteen", "Seventeen","Eighteen", "Nineteen", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety", "Hundred","Thousand","Million","Billion"};

    string toWord(int num){

        string word = "";
        if(num/1000000000){
           word += toWord(num/1000000000) +" Billion "+toWord(num%1000000000);
        }
        else if(num/1000000){
           word += toWord(num/1000000) +" Million "+toWord(num%1000000);
        }
        else if(num/1000){
           word += toWord(num/1000) +" Thousand "+toWord(num%1000);
        }
        else if(num/100){
           word += toWord(num/100) +" Hundred "+toWord(num%100);
        }
        else if(num<=20){
            word += spelling[num];
        }
        else {
            word +=spelling[num/10-2+20] +" "+ spelling[num%10];
        }

        if(word.size() && word[word.size()-1]==' ') word.pop_back();
        return word;
    }

    string numberToWords(int num) {
        if(num==0) return "Zero";

        string ans = toWord(num);

        return ans;
    }
};
