#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
//class Solution  // use two pointers and a fake head
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (head==NULL || n<=0){
//            return NULL;
//        }
//
//        ListNode fakeHead(-1);
//        fakeHead.next = head;
//        ListNode* conductor1 = &fakeHead;
//        ListNode* conductor2 = &fakeHead;
//        for (int i = 0; i < n; i++) {
//            conductor1 = conductor1->next;
//        }
//
//        while(conductor1->next) {
//            conductor1 = conductor1->next;
//            conductor2 = conductor2->next;
//
//        }
//        ListNode* tobeDeleted = conductor2->next;
//        conductor2->next = conductor2->next->next;
//        delete tobeDeleted;
//        return fakeHead.next;
//    }
//};
