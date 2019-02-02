/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1

示例 2:

输入: 16
输出: true
解释: 24 = 16

示例 3:

输入: 218
输出: false

*/
#include <iostream>
using namespace std;
//循环法
bool isPowerOfTwo(int n) {
    //0单独判断 否则会陷入死循环
    if(n<=0) return false;
    while(n%2==0){//若能整除2 则一直取余
        n/=2;
    }
    //n==1代表是2的幂
    if(n==1) return true;
    else return false;
    //return (n==1)
}

//位运算法
/*
判断一个整数是不是2的幂，可根据二进制来分析。2的幂如2,4,8,等有一个特点：

二进制数首位为1，其他位为0，如2为10,4为100

2&（2-1）=0   4&（4-1）=0 

即得出结论如果一个数n为2的幂，则n(n-1)=0
*/
bool isPowerOfTwo2(int n) {
    if(n<=0) return false;
    
    return ((n&(n-1))==0);

}
//递归法
bool isPowerOfTwo3(int n){
    return n>0&&(n==1||((n%2==0)&&isPowerOfTwo3(n/2)));
}



int main(){
    bool flag=isPowerOfTwo3(128);
    cout<<flag<<endl;
    return 0;
}