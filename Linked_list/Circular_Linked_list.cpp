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

void insertfront(int values){
    Node* newNode = new Node(values);
    if(head==NULL){
        head=tail=newNode;
    }
    else{
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
    temp->next=newNode;
    newNode->next=head;
    }
}
};

int main(){
    list ll;
    ll.insertfront(50);
    ll.insertfront(40);
    ll.insertfront(30);
    ll.insertfront(20);
}