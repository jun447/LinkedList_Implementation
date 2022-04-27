#include <iostream>
using namespace std;
class Node {
   public:
    int data;
    Node *next;
//    constructor:
    Node(int data){
       this->data = data;
       this->next = NULL;
    }

     ~Node() {
     int value = this->data;
     //memory free code
     if(this->next!=NULL){
         delete next;
         this->next = NULL;
     }
     cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void InsertAtHead(Node* &head, int data){
       Node* temp=new Node(data);
       temp->next=head;
       head=temp;
//    Node* newNode = new Node(data);
//    newNode->next = head;
//    head = newNode;
}
void InsertAtTail(Node* &tail,int data){
    Node* temp =new Node(data);
    tail->next=temp;
//    tail=tail->next;
    tail=temp;
}
void InsertAtPosition(Node* &head,Node* &tail,int position,int data){
    if(position==1){
//        no need to update head
        InsertAtHead(head,data);
        return;
    }
    Node* temp =head;
    int count =1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
//    Insertig at last position so we need to update tail
    if (temp->next==NULL){
        InsertAtTail(tail,data);
        return;
    }
//    create new node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deleteNode(int position,Node* &head){
//    deleting first and start node
    if(position==1){
      Node* temp = head;
      head=head->next;
//    if we delete this but it will still point to next one
//    so we have to remove this link by pointing to the NULL
      temp->next=NULL;
      delete temp;
    }else{// deleting middle and last node
      Node* curr = head;
      Node* prev =NULL;//because first node ke prev NULL hota hai
      int count=1;
      while(count<position){
          prev=curr;
          curr=curr->next;
          count++;
      }
      prev->next=curr->next;
      curr->next=NULL;
      delete curr;
    }
}
int getLength(Node* &head){
    int count = 0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
int main() {
//    Create a new Node
    Node* node1 =new Node(13);
//    cout<<(*node1).data<<endl;
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    //head pointed to node1
    Node* head=node1;
//    tail ppointer to node1
    Node* tail=node1;
    InsertAtHead(head,12);
    print(head);
    InsertAtHead(head,16);
    print(head);
    InsertAtHead(head,17);
    print(head);
    InsertAtTail(tail,14);
    print(head);
    InsertAtPosition(head,tail,5,15);
    print(head);
    InsertAtPosition(head,tail,1,89);
    print(head);
    deleteNode(2,head);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    cout<<"length of SLL is "<<getLength(head)<<endl;
    return 0;
}
