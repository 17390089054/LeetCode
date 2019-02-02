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
vector<vector<int>> generateMatrix(int n) {
    //极限判断
    if(n<=0) return {};
    //定义结果数组
    vector<vector<int> >res(n,vector<int>(n));
    int i=0,j=0,sum=0;
    res[i][j]=++sum;
    while(sum<n*n){
        //向右
        while(j<n-1&&!res[i][j+1]){
            res[i][++j]=++sum;
        }
        //向下
        while(i<n-1&&!res[i+1][j]){
            res[++i][j]=++sum;
        }
        //向左
        while(j>0&&!res[i][j-1]){
            res[i][--j]=++sum;
        }
        //向上
        while(i>0&&!res[i-1][j]){
            res[--i][j]=++sum;
        }

    }
   return res;
}

int main(){
    int n=1;
    vector<vector<int> >res=generateMatrix(n);
     for(unsigned int i=0;i<res.size();i++){
        for(unsigned j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}