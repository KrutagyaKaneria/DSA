#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  
  Node(int value){
      data=value;
      next=NULL;
  }
}; 
  
 class list{
    Node* head;
    Node* tail;
  
  
public:
  list(){
      head=tail=NULL;
  }
  void push_front(int value){
    Node* newnode = new Node(value);
    if(head==NULL){
        head=tail=newnode;
        return;
    }
    else{
        newnode->next = head;
        head=newnode;
    }
};

void push_back(int value){
    Node* newnode = new Node(value);
    if(head==NULL){
        head=tail=newnode;
        return;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
};

void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

void pop_front(){
    if(head==NULL){
        cout << "linklist is empty"<<endl;
    }
    else{
    Node* temp = head;
    head=temp->next;
    temp->next = NULL;
    delete temp;
    }
}

void pop_back(){
    if(head==NULL){
        cout << "linklist is empty"<<endl;
    }
    Node* temp = head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=NULL;
    delete tail;
    tail = temp;
}

void insertmiddle(int value,int pos){
    if(pos==0){
        push_front(value);
        return;
    }
    Node* newnode = new Node(value);
    Node* temp = head;
    for(int i=0; i<pos-1 ; i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

int search(int key){
    Node* temp=head;
    int idx=0;
    
    while(temp!=NULL){
        if(temp->data==key){
            return idx;
        }
        temp=temp->next;
        idx++;
    }
    return -1;
}
};

int main() {
    list ll;
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_back(1);
    ll.push_back(0);
    ll.insertmiddle(1.1,2);
    ll.pop_front();
    ll.pop_back();
    ll.print();
    
    cout << ll.search(3) << endl;
    return 0;
}