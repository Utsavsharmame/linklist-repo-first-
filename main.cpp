#include <iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  Node(int data) {
    this -> data = data;
    this -> next = NULL;

  }
};
  void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
      cout << temp -> data << " ";
       temp = temp -> next;
    }
  }
  Node* getMiddle(Node* &head) {
    if(head == NULL){
      cout << "LL is empty" << endl;
      return head;
    }
    if(head -> next == NULL){
      // only one ll is there 
      return head;
    }
    // LL  have > 1 node
     Node* slow = head;
     Node* fast = head -> next;
       // -> its a odd and even
     while( slow != NULL && fast != NULL){
      fast = fast -> next;
      if(fast != NULL) {
         fast = fast -> next;
         slow = slow -> next;
      }
     }
     return slow;
  }

int main() {
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);
  Node* sixth = new Node(60);
 
 head -> next = second;
 second -> next = third;
 third -> next = fourth;
 fourth -> next = fifth;
 fifth -> next = sixth;
 sixth -> next =  NULL;

 print(head);
 

  cout << "Middle Node is:" << getMiddle(head) -> data << endl;
       
  return 0;
}