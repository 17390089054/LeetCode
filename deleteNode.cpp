/*
请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

示例 1:

输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], node = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 

说明:

链表至少包含两个节点。
链表中所有节点的值都是唯一的。
给定的节点为非末尾节点并且一定是链表中的一个有效节点。
不要从你的函数中返回任何结果。
 */


#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

//创建链表
ListNode* createList(){
    ListNode *head=new ListNode(0);
    ListNode *p=head;
    cout<<"please input a number (ends with -1)"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        ListNode *temp=new ListNode(data);
        temp->next=p->next;
        p->next=temp;
        p=temp;
        cout<<"please input a number (ends with -1)"<<endl;
        cin>>data;
    }
    return head;
}

//遍历链表
void printList(ListNode *head){
    ListNode *p=head;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
}
//删除节点
void deleteNode(ListNode* node) {
    //极限判断
    if(node==0||node->next==nullptr){
        cout<<"The list is empty or the node is the last node:"<<endl;
        return;
    }
    //删除节点即意味着后一个节点往前覆盖
    ListNode *p=node->next;
    node->val=p->val;
    node->next=p->next;
    delete p;
}

int main(){
    ListNode* head=createList();
    printList(head->next);

    return 0;
}