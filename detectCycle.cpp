/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

进阶：
你是否可以不用额外空间解决此题？
*/

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//创建链表
ListNode *createList()
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    cout << "please input a number (ends with -1)" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        ListNode *temp = new ListNode(data);
        temp->next = nullptr;
        p->next = temp;
        p = temp;
        cout << "please input a number (ends with -1)" << endl;
        cin >> data;
    }
    return head;
}
//打印链表
void printList(ListNode *head)
{
    ListNode *p = head;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

//判断链表是否有环 超时
ListNode *detectCycle(ListNode *head)
{
    //极限判断
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    //找到环
    ListNode *slow = head, *fast = head->next;
    while (fast != nullptr)
    {
        if (fast == slow)
        {
            break;
        }
        else
        {
            fast = fast->next;
            if (fast == nullptr)
            {
                return nullptr;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
    }
    //遍历环，找到入口节点
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

ListNode *detectCycle2(ListNode *head)
{
    //空链表或者单个节点
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    //判断链表是否有环 记录相遇位置
    ListNode *fast = head, *slow = head;
    ListNode *temp = nullptr;
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next)
        {
            fast = fast->next;
        }
        else
        {
            return nullptr;
        }
        if (fast == slow)
        {
            temp = slow;
            break;
        }
    }

    //slow指针从头开始 fast指针从相遇点开始 同时同速度行走 相遇点即为环入口节点
    if (temp)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    else
    {
        return nullptr;
    }
}

//上面写法简化
ListNode *detectCycle3(ListNode *head){
    if(head==nullptr||head->next==nullptr) return nullptr;
    bool cycle=false;
    ListNode *fast=head,*slow=head;
    ListNode *start=nullptr;
    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            cycle=true;
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            start=slow;
            break;
        }
    }
    return cycle?start:nullptr;
}