#include <iostream>

//struct ListNode
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || n<=0){
            return NULL;
        }
        ListNode* conductor = head;
        int counts = 1;
        while (conductor->next != NULL) {
            conductor = conductor->next;
            counts += 1;
        }
        conductor = head;
        if (counts == n) { //if this, just return head->next
            delete head;
            return conductor->next;
        }
        else {
            for (int i = 0; i < counts-n-1; i++) {
                conductor = conductor ->next;
            }
            ListNode* tobeDeleted = conductor->next;
            conductor->next = conductor->next->next;
            delete tobeDeleted;
            return head;
        }


    }
};
