#include <bits/stdc++.h>
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

ListNode* detectCycle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            ListNode* temp = head;

            while (temp != slow) {
                temp = temp->next;
                slow = slow->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main() {

    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n5->next = n3;

    ListNode* ans = detectCycle(n1);

    if (ans == NULL) {
        cout << "No Cycle found";
    } else {
        cout << "Cycle start" << ans->val;
    }

    return 0;
}