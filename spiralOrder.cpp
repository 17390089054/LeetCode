/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <iostream>
#include <vector>
using namespace std;
//蛇形填数法 X
vector<int> spiralOrder1(vector<vector<int>> &matrix)
{
    //结果数组
    vector<int> res;
    int m = matrix.size();    //行数
    int n = matrix[0].size(); //列数
    int i = 0, j = 0, sum = 1;
    res.push_back(matrix[i][j]);
    while (sum < m * n)
    {
        //右移
        while (j < n - 1 && matrix[i][j + 1])
        {
            res.push_back(matrix[i][++j]);
            ++sum;
        }
        //下移
        while (i < m - 1 && matrix[i + 1][j])
        {
            res.push_back(matrix[++i][j]);
            ++sum;
        }
        //左移
        while (j > 0 && matrix[i][j - 1])
        {
            res.push_back(matrix[i][--j]);
            ++sum;
        }
        //上移
        while (i > 0 && matrix[i - 1][j])
        {
            res.push_back(matrix[--i][j]);
            ++sum;
        }
    }
    return res;
}

//边界循环法
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    //极限判断
    if(matrix.empty()||matrix[0].empty()) return {}; 

    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    //上下左右边界
    int up = 0, down = m - 1, left = 0, right = n - 1;
    while (true)
    {
        //右移
        for (int j = left; j <= right; j++)
        {
            res.push_back(matrix[up][j]);
        }
        //上边界超过下边界即完成输出
        if (++up > down)
        {
            break;
        }
        //下移
        for (int i = up; i <= down; i++)
        {
            res.push_back(matrix[i][right]);
        }
        //右边界超过左边界即完成输出
        if (--right < left)
        {
            break;
        }
        //左移
        for (int j = right; j >= left; j--)
        {
            res.push_back(matrix[down][j]);
        }
        //下边界超过上边界
        if (--down < up)
        {
            break;
        }
        //上移
        for (int i = down; i >= up; i--)
        {
            res.push_back(matrix[i][left]);
        }
        //左边界超过有边界即完成输出
        if (++left > right)
        {
            break;
        }
    }
    return res;
}

//环形计数法
vector<int> spiralOrder3(vector<vector<int>> &matrix){
    //极限判断
    if(matrix.empty()||matrix[0].empty()) return {};
    //返回的结果集
    vector<int> res;
    //计算环数
    int m=matrix.size();
    int n=matrix[0].size();
    int c=m>n?(n+1)/2:(m+1)/2;
    int p=m,q=n;
    for(int i=0;i<c;i++,q-=2,p-=2){
        //右移
       for(int col=i;col<i+q;col++) res.push_back(matrix[i][col]);
        //下移
       for(int row=i+1;row<i+p;row++) res.push_back(matrix[row][i+q-1]); 
        //判断特殊环 单行 单列 单个数字
        if(p==1||q==1) break;
        //左移
        for(int col=i+q-2;col>=i;col--) res.push_back(matrix[i+p-1][col]);
        //上移
        for(int row=i+p-2;row>i;row--) res.push_back(matrix[row][i]);
    }
return res;
}


int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<int> res = spiralOrder3(matrix);
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}