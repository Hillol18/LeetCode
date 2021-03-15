class Solution {
public:
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> u_mp;
    string key = "0";
    // Encodes a URL to a shortened URL.
    void setNextKey(){
        int sz = key.size()-1;
        while(sz>=0){
            if(key[sz] == 'Z'){
                key[sz] = '0';
                sz--;
            }
            else{
                int index =0;
                if('0'<=key[sz] && key[sz]<='9'){
                    index = (key[sz]-'0' + 1);
                }
                else if('a'<=key[sz] && key[sz]<='z'){
                    index = 10+key[sz]-'a'+1;
                }
                else if('A'<=key[sz] && key[sz]<='Z'){
                    index = 36+key[sz]-'A'+1;
                }
                key[sz] = chars[index];
                return;
            }
        }
        key.insert(0,"0");

    }

    string encode(string longUrl) {
        string k = key;
        u_mp[k] = longUrl;
        setNextKey();

        return "http://tinyurl.com/" + k;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string prefix="http://tinyurl.com/";
        return u_mp[shortUrl.substr(prefix.size())];

    }
};
