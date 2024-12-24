#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* sort2(Node* &head) {
    // Create dummy nodes
    Node* zeroHead = new Node(-101);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-101);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-101);
    Node* twoTail = twoHead;

    // Traverse the original list
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == 0) {
            // Take out the zero node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            zeroTail->next = temp;
            zeroTail = temp;
        } else if (curr->data == 1) {
            // Take out the 1 node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            oneTail->next = temp;
            oneTail = temp;
        } else if (curr->data == 2) {
            // Take out the 2 node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // Join the lists
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }

    // Clean up dummy nodes
    Node* temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // Return the head of the new sorted list
    return zeroHead;
}

int main() {
    // Create linked list
    Node* head = new Node(0);
    Node* second = new Node(2);
    Node* third = new Node(0);
    Node* fourth = new Node(2);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "Input LL: ";
    print(head);

    // Sort the list
    head = sort2(head);

    cout << "Sorted LL: ";
    print(head);

    return 0;
}
