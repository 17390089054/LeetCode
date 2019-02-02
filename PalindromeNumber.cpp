/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//分解法
bool isPalindrome(int x) {
    //负数直接返回false
    if(x<0) return false;
    //一位数字直接返回true
    if(0<=x&&x<10) return true;
    //数字逐个分解存入数组 
    int num[10];
    int count=0;
    while(x!=0){
        num[count++]=x%10;
        x/=10;
    }
    //在数组中遍历判断是否是回文数
    for(int i=0;i<count/2;i++){
        if(num[i]!=num[count-1-i]){
            return false;
        }
    }
    return true;
}

//分解法改进算法
bool isPalindrome3(int x) {
    if(x<0) return false;
    if(x>=0&&x<10) return true;
    int s=0,x1=x;
    while(x!=0){
        s=s*10+x%10;
        x/=10;
    }
    if(s==x1)
        return true;
    else 
        return false;
}



//字符串法
bool isPalindrome2(int x) {
    //负数直接返回false
    if(x<0) return false;
    //个位数直接返回true
    if(x>=0&&x<10) return true;
    //转化成String
    stringstream ss;
    ss<<x;
    string str=ss.str();
    //在String内进行比较
    int length=str.length();
    for(int i=0;i<length/2;i++){
        if(str[i]!=str[length-1-i]){
            return false;
        }
    }
    return true;
}



int main(){
    bool flag=isPalindrome3(121);
    cout<<flag<<endl;
    return 0;
}