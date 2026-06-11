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

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        // Check if k nodes are available
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;

            temp = temp->next;
        }

        // Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;

        int count = 0;

        while (curr != NULL && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // Connect with remaining groups
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;

    head = obj.reverseKGroup(head, k);

    printList(head);

    return 0;
}