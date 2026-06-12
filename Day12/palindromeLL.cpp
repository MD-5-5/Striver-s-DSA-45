#include<bits/stdc++.h>
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

ListNode* reverseList(ListNode* head) {
if (head == NULL || head->next == NULL) return head;
ListNode* newHead = reverseList(head->next);
head->next->next = head;
head->next = NULL;
return newHead; 
}
bool isPalndrome(ListNode* head){
    if(head==NULL && head->next == NULL) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = reverseList(slow->next);
    ListNode* first = head;
    ListNode* second = newHead;
    while(second!=NULL){
        if(first->val != second->val){
            reverseList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseList(newHead);
    return true;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout<<isPalndrome(head);
    return 0;
}