#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
class Solution {
public:

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0;
        while(tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }

        int lenB = 0;
        while(tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if(lenA > lenB) {

            int diff = lenA - lenB;

            for(int i = 1; i <= diff; i++) {
                tempA = tempA->next;
            }
        }
        else {

            int diff = lenB - lenA;

            for(int i = 1; i <= diff; i++) {
                tempB = tempB->next;
            }
        }

        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
};

int main() {

    // Common Part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution obj;

    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if(ans)
        cout << "Intersection Node = " << ans->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}