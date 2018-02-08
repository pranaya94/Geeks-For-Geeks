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

void reverseList(Node** head){
    struct Node* temp;
    struct Node* p1;
    struct Node* p2;
    
    p1 = NULL;
    p2 = *head;
    temp = NULL;

    while(p2!=NULL){
        temp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = temp;
    }
        *head = p1; //assign new head
        
}

int main() {
    struct Node* head;
    head = initializeList();
    printList(head);
    reverseList(&head);
    cout<<"Reversing List: "<<endl;
    printList(head);
    
    
	return 0;
}
