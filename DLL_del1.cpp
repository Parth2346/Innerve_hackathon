#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node* prev;
    node* next;
    
    node(int v){
        value = v;
        prev = NULL;
        next = NULL;
    }
};
void forwardtraverse(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> value<< " <-> ";
        temp = temp -> next;   
    }cout <<"NULL"<<endl;
}

void backwardtraverse(node* &head){
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;   
    }
    while (temp != NULL){
        cout << temp -> value << " <-> ";
        temp = temp -> prev;
    }cout<< "NULL"<<endl;
}


void delatstart(node* &head){
   
    if(head -> next == NULL){
        free(head);
        return;
    }
   
    node* temp =  head;
    head = head -> next;    
    head -> prev = NULL;
    free(temp);
}


void delatend(node* &head){

    if(head -> next == NULL){
        free(head);
        return;
    }
    node* temp = head;
    while(temp ->next != NULL){
        temp = temp -> next;
    }
    node* newlast = temp ->prev;
    newlast -> next = NULL;
    free(temp);     
}


void delatany(node* &head, int k){
    node* temp = head;
    for(int i = 1; i<(k-1);i++){
        temp = temp -> next;
    }
    node* delnode = temp -> next;
    temp -> next = delnode -> next;

    if(delnode -> next != NULL){
        delnode -> next -> prev = temp;
    }
}


int main(){
   node* n1 = new node(1);
node* n2 = new node(2);
node* n3 = new node(3);
node* n4 = new node(4);
node* n5 = new node(5);
node* n6 = new node(6);

n1->next = n2;
n2->prev = n1;
n2->next = n3;
n3->prev = n2;
n3->next = n4;
n4->prev = n3;
n4->next = n5;
n5->prev = n4;
n5->next = n6;
n6->prev = n5;
node* head = n1;


    forwardtraverse(head);
    backwardtraverse(head);
    delatstart(head);
    forwardtraverse(head);
   //delatend(head)
    //forwardtraverse(head);
    
    delatany(head,3);
    forwardtraverse(head);
}