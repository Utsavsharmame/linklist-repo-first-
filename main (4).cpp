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
    cout << endl; // Added newline for better output formatting
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node* reverseKNodes(Node* &head, int K) {
    if (head == NULL) {
        cout << "LL is empty" << endl;
        return NULL;
    }

    int len = getLength(head);
    if (K > len) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;

    while (count < K && curr != NULL) {
        forward = curr->next; // Save the next node
        curr->next = prev;    // Reverse the current node
        prev = curr;          // Move prev forward
        curr = forward;       // Move curr forward
        count++;
    }

    if (forward != NULL) {
        // Recur for the remaining list
        head->next = reverseKNodes(forward, K);
    }

    return prev;
}
bool checkForLoop(Node* &head){
  if(head == NULL){
    cout << "LL is empty" << endl;
    return false;
  }

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;
    if(fast != NULL) {
      fast = fast -> next;
      slow = slow -> next;
    }
    if(slow == fast){
      // loop found
      return true;

    }
  }
  // fast Null hogaya
  return false;


}
Node* startingPointLoop(Node* &head){
  if(head == NULL){
    cout << "LL is empty" << endl;
    return NULL;
  }

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;
    if(fast != NULL) {
      fast = fast -> next;
      slow = slow -> next;
    }
    if(slow == fast){
       slow = head;
       break;


    }
  }
  while(slow != fast){
    slow = slow -> next;
     fast =  fast -> next;




  }
  return slow;

 

}

Node* removeLoop(Node* &head){
  if(head == NULL){
    cout << "LL is empty" << endl;
    return NULL;
  }

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;
    if(fast != NULL) {
      fast = fast -> next;
      slow = slow -> next;
    }

    if(slow == fast){
       slow = head;
       break;

    }
  }
  // previus creation counter;

  Node*  prev = fast;

  while(slow != fast){
    prev = fast;
    slow = slow -> next;
     fast =  fast -> next;

  }
  prev -> next = NULL;
  return slow;

 

}


int main() {
    // Create linked list
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* nineth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;\
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = nineth;
    nineth->next = seventh;

 //   cout << "Original Linked List: ";
  //  print(head);

    //head = reverseKNodes(head, 7);
/*
    cout << "Reversed Linked List in groups of K: ";
    print(head);
*/
    cout << "Loop is present or not  " << checkForLoop(head) << endl;
     
     cout << " starting point of loop  " <<  startingPointLoop
     (head) -> data << endl;
     removeLoop(head);
     print(head);
     cout << "Loop is present or not  " << checkForLoop(head) << endl;

    return 0;
}
