/*
NULL C语言默认空指针类型 实质上是void*类型指针 
int *p=NULL 在这个表达式中 实际上存在void *到int *的隐式转换
在C++编译器中不允许这种隐式转换 通常用0(有缺陷,不完美)代表空指针类型 即NULL==0
C++11后引入nullptr代表空类型 解决了以前C++版本中0是整数或者NULL的二义性问题
*/
/*

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？
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

//判断链表是否有环
bool hasCycle(ListNode *head)
{
    //判断链表是否为空或者链表是否只有一个节点
    if (head == nullptr || head->next == nullptr)
        return false;
    //定义快慢指针 快指针比慢指针多走两步
    ListNode *fast = nullptr, *slow = nullptr;
    slow = head;
    fast = head->next;
    while (fast != nullptr)
    {
        if (fast == slow)
        {
            return true;
        }
        else
        {
            fast = fast->next;
            if (fast == nullptr)
            {
                return false;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
    }
    return false;
}

