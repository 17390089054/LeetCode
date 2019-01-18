#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>
using namespace std;

map<string,int>cnt;
vector<string> words;

string rpr(const string& s){
    string c=s;
    for(int i=0;i<c.length();i++)
       c[i]=tolower(c[i]);
    sort(c.begin(),c.end());
return c;
}
int main(){
    string str;
    while(cin>>str){
        if(str[0]=='#') break;
        words.push_back(str);
        string s=rpr(str);
        if(!cnt.count(s)) cnt[s]=0;
        cnt[s]++;
     
    }

    vector<string>ans;
    for(int i=0;i<words.size();i++)
        if(cnt[rpr(words[i])]==1) ans.push_back(words[i]);
    sort(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<"\n";

    return 0;
}2