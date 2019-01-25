/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

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

//计算链表存储的值
int getNum(ListNode *head){
    int number=0;
    ListNode *p=head;
    int count=1;
    while(p!=NULL){
        number+=(p->val)*count;
        count*=10;
        p=p->next;
    }
    return number;
}

//大神解法
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    ListNode *res=new ListNode(0);
    ListNode *temp=res;
    int sum=0;//个位的和
    while(l1||l2){
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        //将每位的和取余10同时创建新节点
        temp->next=new ListNode(sum%10);
        sum/=10;
        temp=temp->next;
    }
    //若出现各个都只有1位的情况且溢出 则应该进位
    if(sum){
        temp->next=new ListNode(1);
    }
    return res->next;
}

//链表两数相加 容易溢出 不推荐
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //极限判断
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    ListNode *h1=l1;
    ListNode *h2=l2;
    ListNode *head=(ListNode*)malloc(sizeof(ListNode));
    ListNode *p=head;
    //分别获取number1与number2
    int number1=getNum(h1);
    int number2=getNum(h2);
    //计算number1与number2的总和
    int sum=number1+number2;
    //逐个数字分解
    while(sum>=1){
        int num=sum%10;
        //ListNode *temp=(ListNode*)malloc(sizeof(ListNode));
        //temp->val=num;
        ListNode *temp=new ListNode(num);
        temp->next=NULL;
        p->next=temp;
        p=temp;
        sum/=10;
    }
    return head->next;
}


int main(){
   ListNode *h1= createList();
   cout<<"链表1的结果如下:"<<endl;
   print(h1->next);
   ListNode *h2= createList();
   cout<<"链表2的结果如下:"<<endl;
   print(h2->next);
   //打印两个链表的总和
   ListNode *head=addTwoNumbers(h1->next,h2->next);
   print(head);
   //ListNode *head=addTwoNumbers2(h1->next,h2->next);
   //print(head);
   delete h1,h2,head;
    return 0;
}