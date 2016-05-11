// This was a basic program to add two linked lists.
//
// Things that I learnt:
// 1. Always remember the link list that you want to return, should have its head at the right place.
// 2. Make sure to check all the corner cases. Probablly write down all the test cases that come to your mind.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = NULL, *temp = NULL;
        int n = 0;
        while (l1 != NULL && l2 != NULL) {
            n = l1->val + l2->val + carry;
            carry = n / 10;
            n = n % 10;
            ListNode *newNode = new ListNode(n);
            if (ans == NULL) {
                ans = newNode;
                temp = newNode;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l3 = NULL;
        if (l1 != NULL) l3 = l1;
        if (l2 != NULL) l3 = l2;
        while(l3 != NULL) {
            n = l3->val + carry;
            carry = n / 10; n = n % 10;
            ListNode *newNode = new ListNode(n);
            if (ans == NULL) {
                ans = newNode;
                temp = newNode;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
            l3 = l3->next;
        }
        if (carry != 0) {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return ans;
    }
};

struct ListNode {
    int val;
    ListNode *next = NULL;
    ListNode(int x) : val(x), next(NULL) {}
};
