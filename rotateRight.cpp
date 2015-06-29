//============================================================================
// Name        : rotateRight.cpp
// Author      : hehe
// Version     :
// Copyright   : Your copyright notice
// Description : rotateRight
//    Given a list, rotate the list to the right by k places, where k is non-negative.
//    For example:
//    Given 1->2->3->4->5->NULL and k = 2,
//    return 4->5->1->2->3->NULL.
//    不过我真的不明白k,旋转,啥意思啊
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        else
        if (k==0)
            return head;
        ListNode* swim_ptr = head;
        int len = 0;
        while(swim_ptr->next != NULL) {
            len += 1;
            swim_ptr = swim_ptr->next;
        }
        swim_ptr->next = head; // to make a circle
        len += 1; // this is the real length
        //cout << len << endl;
        swim_ptr = head;
        k %= len;
        for (int i = 0; i < len-k-1; i++)
            swim_ptr = swim_ptr->next;
        head = swim_ptr->next;
//        cout << head->val;
//        cout.flush();
        swim_ptr->next = NULL;
        return head;
    }
};
int main() {
    ListNode lst(1);
    ListNode* head = &lst;
    for(int i = 1; i < 2; i++) {
        ListNode* node = new ListNode(i+1);
        head->next = node;
        head = head->next;
    }

    Solution solution;
    head = solution.rotateRight(&lst, 2);
    for(int i = 0; i < 2; i++) {
        cout << head->val;
        head = head->next;
    }
    return 0;
}
