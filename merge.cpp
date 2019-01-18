#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    sort(nums1.begin(),nums1.end());
    int k=m+n;
    while(m>0 && n>0){
        if(nums1[m-1]>nums2[n-1]){
            nums1[k-1]=nums1[m-1];
            k--;
            m--;
        }
        else{
            nums1[k-1]=nums2[n-1];
            k--;
            n--;
        }
    }
    while(n>0){
        nums1[k-1]=nums2[n-1];
        k--;
        n--;
    }
      


}

int main(){
  int tmp1[]={2,1,3,0,0,0};
  int tmp2[]={2,5,6};
  vector<int> nums1(tmp1,tmp1+3);
  vector<int>nums2(tmp2,tmp2+3);
  merge(nums1,3,nums2,3);
  
  for(int i=0;i<6;i++){
    cout<<nums1[i]<<" ";
  }

  return 0;
}
