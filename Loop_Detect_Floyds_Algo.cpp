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
    fourth->next = third;
    
    return(first);
}

void loopDetector(Node* head){
    Node* ptrSlow = head;
    Node* ptrFast = head;
    
    while(ptrFast->next!=ptrSlow){
        cout<<ptrSlow->data<<endl;
        ptrSlow = ptrSlow->next;
        ptrFast = ptrFast->next->next;
    }
}

int main() {
    struct Node* head;
    head = initializeList();
    loopDetector(head);
    
    
	return 0;
}
