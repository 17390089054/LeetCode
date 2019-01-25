/*

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
//定义节点类型
struct node{
    int data;
    node* next;
};
//尾插法建立链表
node *init(){
    //生成一个头节点
    node *head=new node();
    head->next=NULL;
    cout<<"please input a number(ends with -1)"<<endl;
    node *p=head;
    int data=0;
    cin>>data;
    while(data!=-1){
        //每输入一个数 就新开辟一个节点空间 并让头指针指向它
        node *temp=(node*)malloc(sizeof(node));
        temp->data=data;
        temp->next=NULL;
        p->next=temp;
        p=temp;
        cout<<"please input a number(ends with -1)"<<endl;
        cin>>data;
    }
    //返回头节点
return head;
}

//打印链表
void print(node *head){
    node *p=head->next;
    //循环遍历每个节点
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

//合并两个单链表(循环法)
node* mergeList(node *head1,node* head2){
    //定义一个头节点
    node *head=new node();
    head->next=NULL;
    //定义两个头节点分别指向两个链表
    node * p1=head1->next;
    node * p2=head2->next;
    //定义一个指针指合并后的新链表
    node *last=head;
    //循环判断
    while(p1!=NULL&&p2!=NULL){
        //p1的头节点值比p2的小
        if(p1->data<p2->data){
            last->next=p1;
            p1=p1->next;
            last=last->next;
        }else{//p2的头节点值比p1小
            last->next=p2;
            p2=p2->next;
            last=last->next;
        }
    }

    //p1比p2长
    if(p1!=NULL){
        last->next=p1;
    }
    //p2比p1长
    if(p2!=NULL){
        last->next=p2;
    }
    return head;
}

//合并两个链表(递归法)
node * mergeList2(node *head1,node *head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    node *head=NULL;
    if(head1->data<head2->data){
        head=head1;
        head->next=mergeList2(head1->next,head2);
    }else{
        head=head2;
        head->next=mergeList2(head1,head2->next);
    }
    return head;
}

//递归头节点
node * recursionMergeList(node *head1,node *head2){
    node * head=new node();
    head->next=mergeList2(head1->next,head2->next);
    return head;
}

int main(){
    //初始化链表1
    node *head1=init();
    //打印链表1
    cout<<"链表1结果如下:"<<endl;
    print(head1);
    //初始化链表2
    node *head2=init();
    //打印链表2
    cout<<"链表2结果如下:"<<endl;
    print(head2);
    //循环合并结果
    node *head=mergeList(head1,head2);
    //打印循环合并结果
    cout<<"循环合并结果如下:"<<endl;
    print(head);
    //cout<<"递归合并结果如下:"<<endl;
    //node *head=recursionMergeList(head1,head2);
    //print(head);
    delete head,head1,head2;

    return 0;
}