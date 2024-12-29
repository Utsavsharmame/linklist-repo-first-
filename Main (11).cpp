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

Node* reverse(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  Node* next = curr -> next;
  while(curr != NULL){
    next =  curr -> next;
    curr -> next = prev;
    prev = curr;
    curr =  next;
    
  }
  return prev;
}

Node* solve(Node* &head1, Node* &head2){
  // step 1 : reverse both th ll
  head1 = reverse(head1);
  head2  = reverse(head2);
  
  // step 2 : add both ll
   Node* ansHead = NULL;
   Node* ansTail = NULL;
   int carry =0;
   
   while(head1 != NULL && head2 != NULL){
     
     // calculate sum
       int sum = carry + head1 -> data + head2 -> data;
       // find digit tp create node for
       int digit = sum%10;
       // calculate carry
       
       carry = sum/10;
       
       // create a new node for the digit
       Node* newNode = new Node(digit);
       
       // attact the newNode into the answer wali ll
       if(ansHead == NULL){
         // first nde insrt karke ho 
         ansHead = newNode;
         ansTail = newNode;
         
       }
       else{
         ansTail -> next = newNode;
         ansTail = newNode;
         
       }
       head1  = head1 -> next;
       head2 = head2 -> next;
       
       
       
   }
   /// jab head1 list ki length head2 se jada hogi tab
   
   while(head1 != NULL) {
     int sum = carry + head1 -> data;
      int digit = sum % 10;
       // calculate carry
       
       carry = sum /10;
       Node* newNode = new Node(digit);
       ansTail -> next = newNode;
       ansTail = newNode;
       head1 = head1 -> next;
       
     
     
   }
      /// jab head2 list ki length head1 se jada hogi tab
   while(head2 != NULL) {
     int sum = carry + head2 -> data;
      int digit = sum % 10;
       // calculate carry
       
       carry = sum /10;
       Node* newNode = new Node(digit);
       ansTail -> next = newNode;
       ansTail = newNode;
       head2 = head2 -> next;
       
     
     
   }
   
   // carry handle karo
   while(carry !=0 ){
      int sum = carry;
      int digit = sum %10;
       // calculate carry
       
       carry = sum /10;
       Node* newNode =   new Node(digit);
       ansTail -> next = newNode;
       ansTail = newNode;
     
   }
   
   // step 3 reverse the ll
   ansHead = reverse(ansHead);
    return ansHead;
}


int main() {
  Node* head1 = new Node(1);
  Node* second1 = new Node(0);
  head1 -> next = second1;
  
  Node* head2 = new Node(1);
  Node* second2 = new Node(1);
  Node* third2 = new Node(1);
   
   head2 -> next = second2;
   second2 -> next = third2;
   
   
   Node* ans = solve(head1, head2);
   
   print(ans);
  
  
  
    return 0;
}
