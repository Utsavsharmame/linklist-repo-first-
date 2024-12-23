#include <iostream>
using namespace std;


 class Node{
  public:
  int data;
  Node* next;

  Node(int data){
     this -> data = data;
     this -> next = NULL;

  }
 };


 Node* reverse(Node* head){

    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr -> next;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;

    }
     return prev;

}

 bool checkPalindrome(Node*  &head) {
    if(head == NULL){
      cout << "LL is empty" << endl;
      return true;
    }

    if(head -> next == NULL){

      // only 1 node
       return true;


    }

    // > 1 node in LL

    // step a : find te iddle node;
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL) {
       fast = fast -> next;
       if(fast != NULL){
         fast = fast -> next;
         slow = slow -> next;
       }
    }

    // slow pointer is pointing to middle node



    // step b: reverse LL after middle / slow  node

     Node* reverseLLKaHead = reverse( slow -> next);

      slow -> next = reverseLLKaHead;


      // step C : start comparison 
      Node* temp1 = head;
      Node* temp2 = reverseLLKaHead;

      while(temp2 != NULL){

        if (temp1 -> data != temp2 -> data ){

        // not a palindreome
         return false;

      }
      else{

        // if data is equal, then aga badho jao
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
      }
 }
 return true;
 }


int main() {

  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(20);
  Node* fifth = new Node(10);

  head -> next = second;
  second -> next =third;
  third -> next = fourth;
  fourth -> next= fifth;

  bool isPalindrome = checkPalindrome(head);

  if(isPalindrome){
    cout << "LL is a valid palindrome " << endl;

  }
  else{
    cout << "LL is not a palindrome " << endl;
  }


 
  return 0;
}