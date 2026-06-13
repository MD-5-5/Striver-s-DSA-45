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

ListNode* findnthNode(ListNode* temp, int k) {
    int length = 1;

    while (temp != NULL) {
        if (length == k)
            return temp;

        length++;
        temp = temp->next;
    }

    return temp;
}

ListNode* rotate(ListNode* head, int k) {
    if (head == NULL || k == 0)
        return head;

    ListNode* tail = head;
    int len = 1;

    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    if (k % len == 0)
        return head;

    k = k % len;

    // attach tail to head
    tail->next = head;

    ListNode* newLastNode = findnthNode(head, len - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    int k = 2;
    ListNode* newHead = rotate(a, k);

    printList(newHead);

    return 0;
}