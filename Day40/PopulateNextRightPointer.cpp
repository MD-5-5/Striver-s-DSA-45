#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) {
        val = x;
        left = right = next = NULL;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL || root->left == NULL)
            return root;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        Node* prev = NULL;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                if (q.empty())
                    break;

                q.push(NULL);
            } else {
                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);

                if (prev != NULL)
                    prev->next = curr;
            }

            prev = curr;
        }

        return root;
    }
};

void printUsingNext(Node* root) {
    while (root != NULL) {
        Node* curr = root;

        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << "# ";
        root = root->left;
    }
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    obj.connect(root);

    printUsingNext(root);

    return 0;
}