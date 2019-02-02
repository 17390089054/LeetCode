/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
//利用map键值对求解
int majorityElement(vector<int> &nums)
{
    int size = nums.size();
    if (size == 1)
        return nums[0];
    map<int, int> num_counts;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (!num_counts.count(nums[i]))
        {
            num_counts[nums[i]] = 1;
        }
        else
        {
            num_counts[nums[i]] += 1;
        }
    }
    int temp = 0, index = 0;
    //遍历map
    for (map<int, int>::iterator it = num_counts.begin(); it != num_counts.end(); it++)
    {
        if (it->second > temp)
        {
            temp = it->second;
            index = it->first;
        }
    }
    return index;
}
//摩尔投票法 Moore Voting
/*
*先将第一个数字假设为众数，然后把计数器设为1，
比较下一个数和此数是否相等，若相等则计数器加一，反之减一。
然后看此时计数器的值，若为零，则将下一个值设为候选众数。
以此类推直到遍历完整个数组，当前候选众数即为该数组的众数。
*/
int majorityElement2(vector<int> &nums)
{
    int res = 0, cnt = 0;
    for (int num : nums)
    {
        if (cnt == 0)
        {
            res = num;
            cnt++;
        }
        else
        {
            (res == num) ? cnt++ : cnt--;
        }
    }
    return res;
}

//位操作法
/*
将中位数按位来建立，从0到31位，每次统计下数组中该位上0和1的个数，
如果1多，那么我们将结果res中该位变为1，最后累加出来的res就是中位数了
*/

int majorityElement3(vector<int> &nums)
{
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i)
    {
        int ones = 0, zeros = 0;
        for (int num : nums)
        {
            if (ones > n / 2 || zeros > n / 2)
                break;
            if ((num & (1 << i)) != 0)
                ++ones;
            else
                ++zeros;
        }
        if (ones > zeros)
            res |= (1 << i);
    }
    return res;
}

int main()
{
    vector<int> v{2, 2, 1, 1, 1, 2, 2};
    int num = majorityElement3(v);
    cout << num << endl;
    return 0;
}