/**
 *合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/
#include <iostream>
#include <vector>
#include <algorithm>
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

//合并K个链表
ListNode* mergeKLists(vector<ListNode*>& lists) {
    //极限判断
    if(lists.empty()) return NULL;
    //结果链表
    ListNode *head=new ListNode(0);
    ListNode *p=head;
    //链表数值中间容器
    vector<int>res;
    //遍历集合
    for(int i=0;i<lists.size();i++){
        ListNode *p1=lists[i];
        while(p1!=NULL){
            res.push_back(p1->val);
            p1=p1->next;
        }
    }
    //排序
    sort(res.begin(),res.end());
    //遍历Vector容器
    /*
    for(vector<int>::iterator it=res.begin();it!=res.end();it++){
        cout<<*it<<" ";
    };
    */
    int count=0;
    int size=res.size();
    while(count<size){
        ListNode *temp=new ListNode(res[count++]);
        temp->next=p->next;
        p->next=temp;
        p=temp;
    }
    return head->next;
}

//合并两个单链表(循环法)
ListNode* mergeTwoList(ListNode *head1,ListNode* head2){
    //定义一个头节点
    ListNode *head=new ListNode(0);
    head->next=NULL;
    //定义两个头节点分别指向两个链表
    ListNode * p1=head1;
    ListNode * p2=head2;
    //定义一个指针指合并后的新链表
    ListNode *last=head;
    //循环判断
    while(p1!=NULL&&p2!=NULL){
        //p1的头节点值比p2的小
        if(p1->val<p2->val){
            last->next=p1;
            p1=p1->next;
        }else{//p2的头节点值比p1小
            last->next=p2;
            p2=p2->next; 
        }
        last=last->next;
    }

    //p1比p2长
    if(p1!=NULL){
        last->next=p1;
    }
    //p2比p1长
    if(p2!=NULL){
        last->next=p2;
    }
    return head->next;
}

//合并K个单链表 分治策略
ListNode* mergeKLists2(vector<ListNode*>& lists) {
    if(lists.size()==0) return NULL;
    int n=lists.size();
    while(n>1){
        int k=(n+1)/2;
        for(int i=0;i<n/2;i++){
            lists[i]=mergeTwoList(lists[i],lists[i+k]);
        }
        n=k;
    }
    return lists[0];
}




int main(){
    //测试
    ListNode *head=createList();
    //打印链表
    print(head->next);
    //测试
    ListNode *head1=createList();
    //打印链表
    print(head1->next);
    //测试
    ListNode *head2=createList();
    //打印链表
    print(head2->next);

    vector<ListNode *>lists;
    lists.push_back(head->next);
    lists.push_back(head1->next);
    lists.push_back(head2->next);

    ListNode *head3=mergeKLists2(lists);
    print(head3);
    delete head,head1,head2,head3;
    return 0;
}