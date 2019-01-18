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