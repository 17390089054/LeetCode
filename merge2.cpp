#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      sort(nums1.begin(),nums1.end());
      //遍历nums2中的元素
      for(int i=0;i<n;i++){
        int j=0;
        //在nums1中遍历 直到找到适合nums2[i]的位置
        while(nums1[j]<nums2[i]){
          j++;
        }
        nums1.insert(nums1.begin()+j,nums2[i]);
      }

}

int main(){
  int tmp1[]={1,2,3,0,0,0};
  int tmp2[]={2,5,6};
  vector<int> nums1(tmp1,tmp1+3);
  vector<int>nums2(tmp2,tmp2+3);
  merge(nums1,3,nums2,3);
  for(int i=0;i<6;i++){
    cout<<nums1[i]<<" ";
  }

  return 0;
}