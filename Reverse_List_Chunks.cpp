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

struct Node* reverseList(Node* head,int k){
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = reverseList(next, k); 
 
    /* prev is new head of the input list */
    return prev;
        
}

int main() {
    struct Node* head;
    int k = 3;
    
    head = initializeList();
    printList(head);
    head = reverseList(head,k);
    cout<<"Reversing List: "<<endl;
    printList(head);
    
    
	return 0;
}
