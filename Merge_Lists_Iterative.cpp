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

Node* initializeListA(){
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
    second->data= 3;
    second->next = third;
    third->data = 6;
    third->next = fourth;
    fourth->data = 8;
    fourth->next = NULL;
    
    return(first);
}

Node* initializeListB(){
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    
    first = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    
    first->data = 2;
    first->next = second;
    second->data= 4;
    second->next = third;
    third->data = 5;
    third->next = fourth;
    fourth->data = 7;
    fourth->next = NULL;
    
    return(first);
}

void push(Node** headC,int x){

    Node* newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = x;
    newPtr->next = (*headC);
    (*headC) = newPtr;
}

Node* mergeList(Node* headA, Node* headB){
    struct Node* ptrA = headA;
    struct Node* ptrB = headB;
    struct Node* ptr = NULL;
    
    struct Node* headC = NULL;
    
    while(ptrA!=NULL || ptrB!=NULL){
        
        if(ptrA == NULL){
            push(&headC,ptrB->data);
            ptrB = ptrB->next;
        }
        else if(ptrB == NULL){
            push(&headC,ptrA->data);
            ptrA = ptrA->next;
        }
        else if(ptrA->data < ptrB->data){
            push(&headC,ptrA->data);
            ptrA = ptrA->next;
        }else if(ptrB->data < ptrA->data){
            push(&headC,ptrB->data);
            ptrB = ptrB->next;
        }
        
    }
        return(headC);
}


int main() {
    struct Node* headA;
    struct Node* headB;
    struct Node* headC;
    headA = initializeListA();
    headB = initializeListB();
    cout<<"List A: "<<endl;
    printList(headA);
    cout<<"List B: "<<endl;
    printList(headB);
    cout<<"Merged List :"<<endl;
    headC = mergeList(headA,headB);
    printList(headC);
    
	return 0;
}
