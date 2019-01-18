#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL) {}
};

//尾插法创建单链表
ListNode * createList(){
    ListNode *head=new ListNode(0);
    head->next=NULL;
    cout<<"please input a number (ends with -1):"<<endl;
    ListNode *p=head;
    int data;
    cin>>data;
    while(data!=-1){
        ListNode *temp=(ListNode*)malloc(sizeof(ListNode));
        temp->val=data;
        temp->next=NULL;
        p->next=temp;
        p=temp;
        cout<<"please input a number (ends with -1):"<<endl;
        cin>>data;
    }
    return head;
}

//打印单链表
void print(ListNode *head){
    //ListNode *p=head->next;
    ListNode *p=head;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

//就地反转法
ListNode* reverseList(ListNode* head) {
    if (head==NULL) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=head;
        ListNode* pCur=prev->next;
        while(pCur!=NULL){
            prev->next=pCur->next;
            pCur->next=dummy->next;
            dummy->next=pCur;
            pCur=prev->next;
        }
        return dummy->next;
}

//新建链表，头节点插入法
ListNode * reverseList2(ListNode *head){
    ListNode *dummy=new ListNode(-1);
    ListNode *pCur=head;
    while(pCur!=NULL){
        ListNode * pNext=pCur->next;
        pCur->next=dummy->next;
        dummy->next=pCur;
        pCur=pNext;
    }
    return dummy->next;
}

int main(){

    ListNode *head=createList();
    //打印创建的单链表
    print(head->next);
    //反转后
    cout<<"就地反转法:"<<endl;
    ListNode *head1=reverseList(head->next);
    print(head1);
    delete head,head1;


    return 0;
}