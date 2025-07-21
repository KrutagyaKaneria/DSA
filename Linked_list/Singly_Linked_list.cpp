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

// -------------------------------------------INSERTING MEHODS IN LINKED LIST---------------------------------------------------- 

// Problem 1 - This methos is to add a new node on the 1st position   

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

// Problem 2 - This method is to add a new node to the last of the linked list ;

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

// Problem 3 - This method is used to add a new node in the middle of the linked list as per the position  

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


// --------------------------------------------------DELETION METHODS IN LINKED LIST---------------------------------------------- 

// Problem 1 - This method is used to delete a node from the front means 1st node will be delete

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

// Problem 2 - This method is used to delete a node from back it means last node will be delete

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

// Problem 3 - This method is to delete all the nodes from the linked list and delete it and free up the space 

void deleteLinkedList() {
    Node* ptr = head;
    Node* temp;

    while(ptr) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    head = NULL;
}


// ----------------------------------- SEARCHING AND PRINTING METHODS IN THE LINKED LIST ----------------------------------------

// This method is used the find the index value of a node by passing data 

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

// This method is to traverse the linked list and to print in our terminal

void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

// This method is to find the number of nodes which are present in th linked list 

int lengthoflist(){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp=temp->next;
    }
    cout << cnt << endl;
    return cnt;
}
};

int main() {
    list ll;
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    // ll.push_back(1);
    // ll.push_back(0);
    // ll.insertmiddle(1.1,2);
    // ll.pop_front();
    // ll.pop_back();
    // ll.print();
    ll.lengthoflist();
    
    // cout << ll.search(3) << endl;
    // return 0;
}