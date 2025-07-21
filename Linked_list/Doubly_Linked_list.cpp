#include <iostream>
using namespace std;


class Node {
public:
     int data;
     Node* next;
     Node* prev;

     Node(int value){
        data=value;
        prev=next=NULL;
     }
};

class list{
    Node* head;
    Node* tail;

public:
  list(){
      head=tail=NULL;
  }

// ----------------------------------------INSERTION METHODS IN DOUBLY LINKED LIST -----------------------------------------------

void push_front(int value){
    Node* newNode = new Node(value);
    if(head==NULL){
        head = tail = newNode;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
};

void push_back(int value){
    Node* newNode = new Node(value);
    if(head==NULL){
        head = tail = newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;  
    }
}

void push_middle(int value,int pos){
    Node* newNode = new Node(value);
    if(head==NULL){
        head=tail=newNode;
    }
    else{
      Node* temp = head ;
      for(int i=0;i<pos-1&& temp != NULL;i++){
        temp=temp->next;
      }
      newNode->prev=temp;
      newNode->next=temp->next;
      temp->next=newNode;
      newNode->next->prev=newNode;
    }
}

// -------------------------------------------SEARCHING AND PRINTING EACH NODE IN THE LINKEDLIST------------------------------

void display_forward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ⇄ ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    };

void display_backward() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ⇄ ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    };

// ----------------------------------------------DELETION METHON IN DOUBLY LINKED_LIST-------------------------------------------


void delete_front() {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;  
}


void delete_last(){
    Node*temp=tail;
    if(head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }
    else{
    tail=tail->prev;
    tail->next=NULL;
    }
    delete temp;
}

void delete_middle(int pos) {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position" << endl;
        return;
    }
    if (temp == head) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        delete temp;
        return;
    }
    if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return;
    }

    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

};    



int main(){
    list ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.push_back(1);
    ll.push_middle(3.3,3);
    ll.delete_front();
    ll.delete_last();
    ll.display_forward();
    ll.display_backward();
    
}