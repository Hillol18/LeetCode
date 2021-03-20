#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

bool isUpCase(char c){
  return ('A'<=c && c<='Z');
}

bool isLowCase(char c){
  return ('a'<=c && c<='z');
}

bool isEnd( const string& data, int index){
  return (data.size() == index ||  !(isLowCase(data[index]) || isUpCase(data[index])) );
}

bool cmp (pair<string,pair<int,int>> &a, pair<string, pair<int,int>> &b){
  if(a.second.first == b.second.first){
    return a.second.second<b.second.second;
  }
  return a.second.first > b.second.first;
}

vector<vector<string>> wordCountEngine( const string& document )
{
  // your code goes here

  int n =  document.size();

  unordered_map<string, pair<int, int>> u_mp;

  string temp ="";
  for(int i=0;i<=n;i++){
    char ch = document[i];
    if(ch=='\'')continue;
    if(isUpCase(ch)){
      ch = document[i]-'A'+'a';
    }

    if(isEnd(document, i)){

      if(temp.size() && u_mp.find(temp) != u_mp.end()){
          u_mp[temp].first++;
      }
      else if(temp.size()){
        //cout<<temp<<" "<<temp.size()<<endl;
        u_mp[temp] = make_pair(1, i);
      }
      temp = "";
    }
    else{
      temp += ch;
    }
  }

  vector<pair<string, pair<int,int>>> data;

  auto it = u_mp.begin();

  while(it != u_mp.end()){
    data.push_back(make_pair(it->first, make_pair(it->second.first, it->second.second)));
    //cout<<it->first<<endl;
    it++;
  }

  sort(data.begin(), data.end(), cmp);

  vector<vector<string>> ans;
  vector<string> t(2);
  for(int i=0;i<data.size();i++){
    t[0] = data[i].first;
    t[1] = to_string(data[i].second.first);
    ans.push_back(t);
    //cout<<data[i].first<<" "<<data[i].second.first<<endl;
  }
  return ans;
}

int main() {
  const string input = "Practice makes perfect, you'll get perfecT by practice. just practice! just just just!!";
  wordCountEngine(input);
  return 0;
}

/*

Please give test cases a shot when you are ready
makes perfect
Test Case #1
Input:

"Practice makes perfect, you'll get perfecT by practice. just practice! just just just!!"
Expected:

[["just","4"],["practice","3"],["perfect","2"],["makes","1"],["youll","1"],["get","1"],["by","1"]]
Actual:

[["practice","3"],["perfect","2"],[" just","2"],["just","2"],["makes","1"],[" youll","1"],["get","1"],["by","1"]]
StdOut:
practice 3
perfect 2
 just 2
just 2
makes 1
 youll 1
get 1
by 1
Test Case #2
Input: "To be, or not to be, that is the question:",Expected: [["to","2"],["be","2"],["or","1"],["not","1"],["that","1"],["is","1"],["the","1"],["question","1"]],Actual: [["to","2"],["be","2"],[" or","1"],["not","1"],[" that","1"],["is","1"],["the","1"],["question","1"]]
Test Case #3
Input: "Every book is a quotation; and every house is a quotation out of all forests, and mines, and stone quarries; and every man is a quotation from all his ancestors. ",Expected: [["and","4"],["every","3"],["is","3"],["a","3"],["quotation","3"],["all","2"],["book","1"],["house","1"],["out","1"],["of","1"],["forests","1"],["mines","1"],["stone","1"],["quarries","1"],["man","1"],["from","1"],["his","1"],["ancestors","1"]],Actual: [["every","3"],["is","3"],["a","3"],["quotation","3"],[" and","3"],[" ","3"],["all","2"],["book","1"],[" house","1"],["out","1"],["of","1"],["forests","1"],["mines","1"],["and","1"],["stone","1"],["quarries","1"],["man","1"],["from","1"],["his","1"],["ancestors","1"]]
Test Case #4
Input: "I have failed over and over and over again in my life and that is why I succeed.",Expected: [["over","3"],["and","3"],["i","2"],["have","1"],["failed","1"],["again","1"],["in","1"],["my","1"],["life","1"],["that","1"],["is","1"],["why","1"],["succeed","1"]],Actual: [["over","3"],["and","3"],["i","2"],["have","1"],["failed","1"],["again","1"],["in","1"],["my","1"],["life","1"],["that","1"],["is","1"],["why","1"],["succeed","1"]]
Test Case #5
Input: "Look If you had One shot, Or one opportunity, To seize everything you ever wanted, In one moment, Would you capture it, Or just let it slip?",Expected: [["you","3"],["one","3"],["or","2"],["it","2"],["look","1"],["if","1"],["had","1"],["shot","1"],["opportunity","1"],["to","1"],["seize","1"],["everything","1"],["ever","1"],["wanted","1"],["in","1"],["moment","1"],["would","1"],["capture","1"],["just","1"],["let","1"],["slip","1"]],Actual: [["you","3"],["one","3"],[" or","2"],["it","2"],["look","1"],["if","1"],["had","1"],["shot","1"],["opportunity","1"],[" to","1"],["seize","1"],["everything","1"],["ever","1"],["wanted","1"],[" in","1"],["moment","1"],[" would","1"],["capture","1"],["just","1"],["let","1"],["slip","1"]]
Test Case #6
Input: "Cause I'm Slim Shady, yes I'm the real Shady, All you other Slim Shadys are just imitating So won't the real Slim Shady, please stand up, Please stand up, Please stand up"

*/
