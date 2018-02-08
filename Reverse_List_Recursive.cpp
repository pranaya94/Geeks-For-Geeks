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
       cout<<"first "<<first->data<<" rest is null"<<endl;
       return;
   }else{
       cout<<"local rest is : "<<rest->data<<endl;
   }
   reverseRecursive(&rest);
   first->next->next = first; 
   cout<<"first->next :"<<first->next->data<<" linked to first "<<first->data<<endl;
   first->next = NULL;
   *head = rest;
   cout<<"but here rest is :"<<rest->data<<endl;
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
