#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
   
     int number=0;
    if(nums.size()==0) return 0;
    for(int i=0;i<nums.size();i++)
    {
      if(nums[i]!=nums[number]){
        number++;
        nums[number]=nums[i];
      }
    }

    return ++number;
}

int main(){
  int tmp[]={0,0,1,1,1,2,2,3,3,4};
  std::vector<int> v(tmp,tmp+3);
  int num=removeDuplicates(v);
  cout<<num<<endl;
  return 0;
}
