#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    char data;
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
    
    first->data = 'A';
    first->next = second;
    second->data= 'N';
    second->next = third;
    third->data = 'N';
    third->next = fourth;
    fourth->data = 'A';
    fourth->next = NULL;
    
    return(first);
}

Node* pushToStack(Node* head){
    struct Node* top = NULL;
    struct Node* ptr = head;
    struct Node* newPtr;
    
    while(ptr!=NULL){
        newPtr = (Node*)malloc(sizeof(Node));
        newPtr->data = ptr->data;
        newPtr->next = top;
        top = newPtr;
        ptr = ptr->next;
    }

    return(top);
}

bool isPalindrome(Node* head, Node* top){
    bool flag = true;
    
    while(head !=NULL){
        if(head->data != top->data){
            flag = false;
        }
        head = head->next;
        top = top->next;
    }   
    
    return(flag);
}

int main() {
    struct Node* head;
    struct Node* top;
    bool isPal = false;
    head = initializeList();
    top = pushToStack(head);
    isPal = isPalindrome(head,top);
    cout<<isPal;
    
	return 0;
}
