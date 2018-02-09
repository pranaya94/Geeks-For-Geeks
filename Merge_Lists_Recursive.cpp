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



Node* mergeListRecursive(Node* ptrA, Node* ptrB){
    struct Node* ptr = NULL;
    
    if(ptrA == NULL){
        return(ptrB);
    }
    
    if(ptrB == NULL){
        return(ptrA);
    }
    
    if(ptrA->data < ptrB->data){
        ptr = ptrA;
        ptr->next = mergeListRecursive(ptrA->next,ptrB);
    }else if(ptrB->data < ptrA->data){
        ptr = ptrB;
        ptr->next = mergeListRecursive(ptrA,ptrB->next);
    }   
    
        return(ptr); //after returning from recursive calls
        //we go down the stack to the orignal call where ptr 
        //was first assigned
    
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
    headC = mergeListRecursive(headA,headB);
    printList(headC);
    
	return 0;
}
