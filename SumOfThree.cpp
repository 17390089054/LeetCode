#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
      vector <vector<int> > res;
      sort(nums.begin(),nums.end());
      int size=nums.size();
      for(int k=0;k<size;k++){
          int i=k+1,j=size-1;
          //查找两数之和为当前元素的相反数
          while(i<j){
            int value=nums[i]+nums[j];
            if(-nums[k]==value){
              vector<int>list;
              list.push_back(nums[k]);
              list.push_back(nums[i]);
              list.push_back(nums[j]);
              res.push_back(list);

              //重值处理 判断元素是否重复 i必须小于j 不能越界
              while(i<j && nums[i]==nums[i+1])
                  i++;
              while(i<j && nums[j]==nums[j-1])
                  j--;
            i++;
            j--;
            }else if(-nums[k]<value){
                j--;
            }else{
              i++;
            }
          }
          //重值处理 一轮匹配结束后 匹配原数组中与当前元素相等的元素为止
          while(k<size-1&&nums[k]==nums[k+1])
                k++;
      }
      return res;
    }

int main(){
    int arr[]={-1, 0, 1, 2, -1, -4};
    vector<int>nums(arr,arr+6);
    vector<vector<int> > v=threeSum(nums);
    for(int i=0;i<v.size();i++){
      cout<<"[";
      for(int j=0;j<3;j++){
        cout<<v[i][j]<<" ";
      }
      cout<<"] ";
    }
  return 0;
}
