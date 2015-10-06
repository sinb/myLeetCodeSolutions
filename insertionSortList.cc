#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//
//插入排序
//每次循环找到一个元素在当前排好的结果中相对应的位置，
//然后插进去，经过n次迭代之后就得到排好序的结果了
//链表的基本操作了，搜索并进行相应的插入。
//时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);

        for (ListNode *cur = head; cur != nullptr;) {
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode *tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }
    //assume head is sorted, 比如1,4,5,7,x=6会找到5的位置返回
    ListNode* findInsertPos (ListNode* head, int x)
    {
        ListNode *pre = nullptr;
        for (ListNode *cur = head; cur != nullptr && cur->val <= x;pre = cur, cur = cur->next)
            ;
        return pre;
    }
};
int main()
{
    Solution s;
    ListNode a(2);
    ListNode b(5);  a.next = &b;
    ListNode c(6);  b.next = &c;
    ListNode d(1);  c.next = &d;
    ListNode e(9);  d.next = &e;
    ListNode *insert_ptr = s.insertionSortList(&a);
    for (auto i = insert_ptr; i != nullptr; i = i->next)
        cout << i->val << endl;
}
