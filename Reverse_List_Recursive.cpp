#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    int data;
};

void printList(Node* head){
    struct Node* ptr;
    ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data;
        cout<<endl;
        ptr = ptr->next;
    }
}

Node* initializeList(){
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    
    first = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    
    first->data = 1;
    first->next = second;
    second->data= 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    
    return(first);
}

void reverseRecursive(Node** head){
   struct Node* first;
   struct Node* rest;
   

   first = (*head);
   rest = first->next;
   
   if(rest == NULL){
       return;
   }
   reverseRecursive(&rest);
   first->next->next = first; //rest->next doesn't exist so cant use that dummy
   first->next = NULL;
   *head = rest; //how is this being assigned, should rest not change going down the stack ?
   return;
}

int main() {
    struct Node* head;
    head = initializeList();
    printList(head);
    reverseRecursive(&head);
    cout<<"Reversing List: "<<endl;
    printList(head);
    
    
	return 0;
}
