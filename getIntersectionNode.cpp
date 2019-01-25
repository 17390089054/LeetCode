/*
编写一个程序，找到两个单链表相交的起始节点。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

示例 2：
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。 

示例 3：
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

#include <iostream>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
//创建链表
ListNode* createList(){
    ListNode *head=new ListNode(0);
    ListNode *p=head;
    cout<<"please input a number (ends with -1):"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        ListNode *temp=new ListNode(data);
        temp->next=p->next;
        p->next=temp;
        p=temp;
        cout<<"please input a number(ends with -1):"<<endl;
        cin>>data;
    }
return head;
}
//打印链表
void printList(ListNode *head){
    ListNode *p=head;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
cout<<endl;
}

//把a、b链表弄成等长，然后一起遍历，最先相等的结点就是交点。
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL||headB==NULL) return NULL;
    ListNode *ha=headA;
    ListNode *hb=headB;
    //计算链表长度 同时将指针移至最后一个节点
    int la,lb=0;
    while(ha->next){
        ha=ha->next;  
        la++;
    }
    while(hb->next){
        hb=hb->next;
        lb++;
    }
    if(ha!=hb) return NULL;
    ha=headA;
    hb=headB;

   //la长度大于lb 则交换长度与指针
   if(la>lb){
       swap(la,lb);
       swap(ha,hb);
   }
   //将ha定位至于hb同一位置
   int i=0;
   while(hb!=NULL&&la+i!=lb){
       hb=hb->next;
       i++;
   }

    while(ha&&hb){
        if(ha==hb) return ha;
        ha=ha->next;
        hb=hb->next;
    }

}
//这个思路就是 ListA + ListB = A + intersection + Bb + intersection
//ListB + ListA = Bb + intersection + A + intersection
//用大A表示ListA里面非共有 Bb表示listB里面非共有的，可以看到在第二个intersection的开头两个链表长度是一样的，必然相等
//所以我们可以遍历A再遍历B，另一个遍历B再遍历A，两个指针必定在第二个交集处相遇，没有交集就是空指针

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    if(!headA||!headB) return NULL;
    ListNode *ha=headA;
    ListNode *hb=headB;
    while(ha!=hb){
        if(!ha){
            ha=headB;
        }else{
            ha=ha->next;
        }
        if(!hb){
            hb=headA;
        }else{
            hb=hb->next;
        }
    }
    return ha;
}



int main(){
    ListNode *headA=createList();
    printList(headA->next);
    ListNode *headB=createList();
    printList(headB->next);
    ListNode*head=getIntersectionNode2(headA->next,headB->next);
    cout<<head<<endl;
    return 0;
}