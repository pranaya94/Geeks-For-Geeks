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

Node* insertAtFrontA(Node* head,int n){ //this head pointer is a copy
//of the head pointer passed
//original head in int main() not changed so we need to return it
    struct Node* newPtr;
    newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = n;
    newPtr->next = head;
    head = newPtr;
    return(head);
}

int counter(Node* head, int x){
    static int c = 0;
    if(head == NULL){
        return 0;
    }
    counter(head->next,x);
    if(head->data == x){
        c++;
    }
    return c;
}


int main() {
    struct Node* head;
    head = initializeList();
    printList(head);
    cout<<"Inserting element at front A****************"<<endl;
    head = insertAtFrontA(head,0);
    printList(head);
    cout<<"Inserting element at front A****************"<<endl;
    head = insertAtFrontA(head,0);
    printList(head);
    cout<<"Inserting element at front A****************"<<endl;
    head = insertAtFrontA(head,0);
    printList(head);
    
    int count;
    count = counter(head,0);
    cout<<"0 found :"<<count<<"times";
    
    
	return 0;
}
