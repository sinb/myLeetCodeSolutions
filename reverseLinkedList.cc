#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//链表逆序就是把没一个节点的指针反过来
//不要移动节点里面存的内容
//从头到尾遍历,改变每个节点的next项到指回上一个的地址
//也就是每次都打断链表,保存必要的信息(下一个的地址,上一个的地址)就行了
//参考https://www.youtube.com/watch?v=sYcOK51hl-A
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current, *prev, *next;
        current = head;
        prev = NULL;
        while (current != NULL)
        {
            next = current->next; // store step, store current->next cause we will change current->next
            current->next = prev; // this is the reverse step
            prev = current; // prev is always moving
            current = next; // current is always moving
        }
        head = prev;
        return head;
    }
};

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    ListNode *head = &a;
    Solution s;
    head = s.reverseList(head);

    while (head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }

}
