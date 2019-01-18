#include <iostream>
#include <vector>
using namespace std;
//正序倒序法实现O(n)
vector<int> productExceptSelf(vector<int>& nums) {
    int size=nums.size();
    //正序乘积
    vector<int> a1;
    int temp=1;
    for(int i=0;i<size;i++){
        temp*=nums[i];
        a1.push_back(temp);
    }
   
    //倒序乘积
    vector<int>a2;
    int temp2=1;
    for(int j=size-1;j>=0;j--){
        temp2*=nums[j];
        a2.push_back(temp2);
    }

    //利用output[i]=a1[i-1]*a2[i+1]
    for(int k=1;k<size-1;k++){
        nums[k]=a1[k-1]*a2[size-2-k];
    }
    //首尾特殊处理
    nums[0]=a2[size-2];
    nums[size-1]=a1[size-2];

  return nums;
}

//除法实现 不建议 易出现除0错误
vector<int> productExceptSelf2(vector<int>& nums) {
    int size=nums.size();
    int temp=1;
    for(int i=0;i<size;i++){
        temp*=nums.at(i);
    }
    for(int j=0;j<size;j++){
        nums[j]=temp/nums.at(j);
    }
    return nums;
}


int main(){
    //int nums[]={1,2,3,4};
    vector<int>nums={1,2,3,4};
    productExceptSelf2(nums);
    for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
        cout<<(*it)<<" ";
    }
    return 0;
}