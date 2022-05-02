#include <bits/stdc++.h>
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
void print(Node* &head,Node* &tail){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
}
void deleteNode(int position,Node* &head,Node* &tail){
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

    Node* temp = head;
    while(temp !=NULL){
        tail=temp;
        temp=temp->next;
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
bool detectLoop(Node* head){
    if(head==NULL)
        return false;
    map<Node* ,bool> visited;
    Node* temp=head;
    while(temp!=NULL){
        //cycle is present in the list
        if(visited[temp]){
            cout<<"Present on the element "<<temp->data<<endl;
//            cout<<"Present on the element "<<visited[temp]<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
Node* floydDetectionLoop(Node* head){
    if (head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            cout<<"Present on the element "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
Node* gettingStartingNode(Node* head){
    if (head==NULL){
        return NULL;
    }
    Node* intersection= floydDetectionLoop(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeLoop(Node* head){
    if (head==NULL)
        return ;
    Node* loop=gettingStartingNode(head);
    Node* temp=loop;
    while(temp->next!=loop){
        temp=temp->next;

    }
    temp->next=NULL;
}
int main() {
//    Create a new Node
    Node* node1 =new Node(13);
//    cout<<(*node1).data<<endl;
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    //head pointed to node1
    Node* head=node1;
// //   tail ppointer to node1
    Node* tail=node1;
    InsertAtHead(head,12);
    print(head,tail);
    InsertAtHead(head,16);
    print(head,tail);
    InsertAtHead(head,17);
    print(head,tail);
    InsertAtTail(tail,14);
    print(head,tail);
    InsertAtPosition(head,tail,5,15);
    print(head,tail);
    InsertAtPosition(head,tail,1,89);
    print(head,tail);
    deleteNode(7,head,tail);
    print(head,tail);
    cout<<"length of SLL is "<<getLength(head)<<endl;
//    Checking loop in LinkedList
   if(detectLoop(head)){
       cout<<"Cycle is Present "<<endl;
   }else{
       cout<<"Cycle is Not Present "<<endl;
   }
//   Creating loop in LinkedList
    tail->next=head->next;
//   Checking loop in LinkedList
   if(floydDetectionLoop(head)){
        cout<<"Cycle is Present "<<endl;
    }else{
        cout<<"Cycle is Not Present "<<endl;
    }
   Node* loop=gettingStartingNode(head);
   cout<<"Loop starts at "<<loop->data<<endl;
   cout<<"remove loop called"<<endl;
    removeLoop(head);
    if(detectLoop(head)){
        cout<<"Cycle is Present "<<endl;
    }else{
        cout<<"Cycle is Not Present "<<endl;
    }
   return 0;
}
