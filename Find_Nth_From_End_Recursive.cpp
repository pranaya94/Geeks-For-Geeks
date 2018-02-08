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
    
    first = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    
    first->data = 1;
    first->next = second;
    second->data= 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    return(first);
}

Node* insertAtFront(Node* head,int n){
    struct Node* newPtr;
    newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = n;
    newPtr->next = head;
    head = newPtr;
    
    return(head);
}


Node* insertAtEnd(Node* head,int n){
    struct Node* newPtr;
    struct Node* ptr;
    newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = n;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = newPtr;
    newPtr->next = NULL;
   
    return(head);
}
/* 0 1 2 3 */

Node* insertAfter(Node* head,int n,int x){
    struct Node* newPtr;
    struct Node* ptr;
    struct Node* temp;
    
    newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = n;
    ptr = head;
    while(ptr!=NULL && ptr->data!=x){
        ptr=ptr->next;
    }
    
    if(ptr!=NULL){
        temp = ptr->next;
        ptr->next = newPtr;
        newPtr->next = temp;
    }else{
        cout<<"Element not found"<<endl;
        return(head);
    }
    
    return(head);
}

void findFromEnd(Node* head,int n){
    static int i = 0;
    if(head==NULL){
        return;
    }
    findFromEnd(head->next,n);
    if(++i == n){
        cout<<"Second element from end is : "<<head->data;
    }
}

int main() {
    struct Node* head;
    bool found = false;
    
    head = initializeList();
    printList(head);
    cout<<"Inserting element at front ****************"<<endl;
    head = insertAtFront(head,0);
    printList(head);
    cout<<"Inserting element at end ****************"<<endl;
    head = insertAtEnd(head,4);
    printList(head);
    cout<<"Inserting element after ****************"<<endl;
    head = insertAfter(head,9,4);
    printList(head);

    int x;
    findFromEnd(head,2);
   
    
    
	return 0;
}
