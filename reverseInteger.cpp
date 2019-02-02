/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321

 示例 2:

输入: -123
输出: -321

示例 3:

输入: 120
输出: 21

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
#include <iostream>
#include <limits>
using namespace std;
//错误解法
int reverse(int x)
{
    if (x == 0)
        return x;
    //正负号
    bool gtZero = true;
    long x1 = x;
    if (x1 < 0)
    {
        gtZero = false;
        x1 = 0 - x1;
    }
    //结果数组
    int res[10];
    int count = 0;
    //分解 存入数组
    while (x1 > 0)
    {
        int temp = x1 % 10;
        x1 /= 10;
        res[count++] = temp;
    }
    int result = 0;
    //数字拼接

    for (int i = 0; i < count - 1; i++)
    {
        if (i == 0 && res[i] == 0)
        {
            continue;
        }
        else
        {
            if (result > INT32_MAX / 10 || result == INT32_MAX && res[i + 1] > 7)
            {
                return 0;
            }
            result += res[i];
            result *= 10;
        }
    }
    result += res[count - 1];

    if (!gtZero)
        result = 0 - result;
    return result;
}

//通过算法
int reverse2(int x)
{
    if ((x < 10) &&( x > -10))
        return x;
    long result = 0;
    const int int_max=0x7fffffff;
    const int int_min=0x80000000;
    //正负号
    bool flag = true;
    if (x < 0)
    {
        x = 0 - x;
        flag = false;
    }
    //分解的同时拼接
    while (x != 0)
    {
        result = result * 10 + x % 10;
        x /= 10;
    }
    if (!flag)
        result = 0 - result;
    if ((result > int_max) || (result < int_min))
        return 0;
    return result;
}

int main()
{
    int result = reverse2(-2147483648);
    cout << result << endl;
    return 0;
}