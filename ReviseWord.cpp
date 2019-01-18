#include <iostream>
using namespace std;
string reverseWords(string s) {
    if(s.length()<=1) return s;
    int len=s.length();
    for(int i=0;i<len/2;i++){
        char c;
        c=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=c;
    }
return s;
}
int main(){
    string s="Let's take LeetCode contest";
    cout<<reverseWords(s);
    return 0;
}