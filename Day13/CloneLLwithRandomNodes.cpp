#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* random;

    ListNode(int x) {
        val = x;
        next = NULL;
        random = NULL;
    }
};

ListNode* copyRandomList(ListNode* head) {
    if (head == NULL)
        return NULL;

    ListNode* temp = head;

    // Step 1: Create copy ListNodes in between
    while (temp != NULL) {
        ListNode* copyListNode = new ListNode(temp->val);

        copyListNode->next = temp->next;
        temp->next = copyListNode;

        temp = copyListNode->next;
    }

    // Step 2: Assign random pointers
    temp = head;

    while (temp != NULL) {
        if (temp->random != NULL)
            temp->next->random = temp->random->next;

        temp = temp->next->next;
    }

    // Step 3: Separate original and copied list
    ListNode* dummy = new ListNode(-1);
    ListNode* copyTail = dummy;

    temp = head;

    while (temp != NULL) {
        ListNode* copyListNode = temp->next;

        temp->next = copyListNode->next;
        copyTail->next = copyListNode;

        copyTail = copyTail->next;
        temp = temp->next;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << "ListNode = " << head->val;

        if (head->random)
            cout << ", Random = " << head->random->val;
        else
            cout << ", Random = NULL";

        cout << endl;

        head = head->next;
    }
}

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);

    a->next = b;
    b->next = c;
    c->next = d;

    a->random = c; // 1 -> 3
    b->random = a; // 2 -> 1
    c->random = d; // 3 -> 4
    d->random = b; // 4 -> 2

    cout << "Original List:\n";
    printList(a);

    ListNode* clonedHead = copyRandomList(a);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}