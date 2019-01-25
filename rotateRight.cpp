/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
*/
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){};
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
        cout<<"please input a number (ends with -1):"<<endl;
        cin>>data;
    }
    return head;
}
//打印链表
void print(ListNode*head){
    if(head==NULL) {
        cout<<"链表为空!"<<endl;
        return;
    }
    ListNode *p=head;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
//旋转列表(循环法) 超时
ListNode* rotateRight(ListNode* head, int k) {
    //极限判断
    if(head==NULL) return NULL;
    //一个元素
    if(head->next==NULL) return head;
    ListNode *prev=NULL;
    int count=0;
    while(count<k){
        ListNode *pCur=head;
        //找到最后一个非空结点以及它的前驱结点 记录它们的地址信息
        while(pCur->next!=NULL){
            prev=pCur;
            pCur=pCur->next;
        }
        //将最后一个非空结点的地址更新为头结点地址
        prev->next=pCur->next;
        pCur->next=head;
        head=pCur;

        count++;
    }
    return head;
}

//旋转链表(快慢指针)
ListNode *rotateRight2(ListNode *head, int k) {
    //空链表
    if(!head) return NULL;
    //一个元素
    if(head->next==NULL) return head;
    //计算链表长度
    int n=0;
    ListNode *p=head;
    while(p){
        p=p->next;
        n++;
    }
    //对于旋转次数大于链表长度的 对长度取余
    k%=n;
    //初始化快慢指针
    ListNode *fast=head,*slow=head;
    //快指针比慢指多走K步
    for(int i=0;i<k;i++){
        fast=fast->next;
    }

    //快慢指针同时走 当快指针到达末尾时 慢指针指向的下一个即为旋转后的表头结点
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }

    fast->next=head;
    head=slow->next;
    slow->next=NULL;

return head;
}

/*
先遍历整个链表获得链表长度n，然后此时把链表头和尾链接起来，
再往后走n - k % n个节点就到达新链表的头结点前一个点，这时断开链表即可。
*/
ListNode *rotateRight3(ListNode *head, int k) {
    if(!head) return NULL;
    ListNode *p=head;
    int n=1;
    while(p->next){
        ++n;
        p=p->next;
    } 
    p->next=head;
    int m=n-k%n;
    for(int i=0;i<m;i++){
        p=p->next;
    }
    head=p->next;
    p->next=NULL;
return head;
}



int main(){
    //创建链表
    ListNode *head=createList();
    //打印链表
    print(head->next);
    ListNode *h=rotateRight3(head->next,2000000000);
    print(h);
    return 0;
}
