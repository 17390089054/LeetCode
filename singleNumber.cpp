/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1

示例 2:

输入: [4,1,2,1,2]
输出: 4

*/

#include <iostream>
#include <vector>
using namespace std;
//暴力破解
int singleNumber(vector<int>& nums) {
    int size=nums.size();
    if(size==1) return nums.at(0);
    //标记数组
    vector<int> flags(size);
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(nums.at(i)==nums.at(j)){
               flags[i]=1;
               flags[j]=1;
            }
        }
    }
    int num=0;
    for(int k=0;k<size;k++){
        if(!flags[k]){
            num=nums[k];
        }
    }
return num;
}

//异或法
int singleNumber2(vector<int>& nums) {
    int size=nums.size();
    if(size==1) return nums[0];
    int num=0;
    //相同的数异或结果为0 不同的数异或结果为该数本身
    for(int i=0;i<size;i++){
        num=num^nums[i];
    }
    return num;
}




int main(){
    vector<int>v{4,1,2,1,2};
    int num=singleNumber2(v);
    cout<<num<<endl;
    return 0;
}