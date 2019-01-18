#include <iostream>
#include <limits>
using namespace std;
int myAtoi(string str)
{
    //计算结果
    int num = 0;
    //正负符号
    bool gtZero = true;
    //符号出现一次
    bool flag = true;
    //字符中的数字
    string res = "";
    //去除字符串首尾的空格
    if (!str.empty())
    {
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
    }

    //将字符串转换成字符数组
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            //更新符号值
            if (flag)
            {
                str[i] == '-' ? gtZero = false : true;
                flag = false;
                continue;
            }
            else
            {
                break;
            }
        }
        else if (48 <= str[i] && str[i] <= 57)
        {
            res += str[i];
            if (i < str.length() - 1 && (str[i + 1] > 57 || str[i + 1] < 48))
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    //是否溢出
    bool overflow = false;
    int temp = 0;
    if (res.length() >= 1)
    {
        for (int j = 0; j < res.length() - 1; j++)
        {
            temp = res[j] - '0';
            //正负判定
            temp = gtZero ? temp : 0 - temp;
            num += temp;

            //溢出判断
            if (num > INT32_MAX / 10 || (num == INT32_MAX / 10 && (res[j + 1] - '0') > 7))
            {
                num = INT32_MAX;
                overflow = true;
                break;
            }
            if (num < INT32_MIN / 10 || (num == INT32_MIN / 10 && (res[j + 1] - '0') > 8))
            {
                num = INT32_MIN;
                overflow = true;
                break;
            }
            num *= 10;
        }
        if (!overflow)
        {
            int t = res[res.length() - 1] - '0';
            t = gtZero ? t : 0 - t;
            num += t;
        }
    }
    return num;
}

int main()
{
    string str = "-91283472332";
    int res = myAtoi(str);
    cout << res << endl;
    return 0;
}