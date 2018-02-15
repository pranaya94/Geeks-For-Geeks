#include <iostream>
using namespace std;

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

void findIntersection(Node*,Node*);

int main() {
    
    struct Node* head1 = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
    struct Node* sixth = NULL;
    
    head1 = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    fifth = (Node*)malloc(sizeof(Node));
    sixth = (Node*)malloc(sizeof(Node));
    
    head1->data = 1;
    head1->next = second;
    second->data= 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = sixth;
    sixth->data = 6;
    sixth->next  = NULL;
    
    
    struct Node* head2 = NULL;
    struct Node* second2 = NULL;
    
    head2 = (Node*)malloc(sizeof(Node));
    second2 = (Node*)malloc(sizeof(Node));
    
    head2->data = 10;
    head2->next = second2;
    second2->data= 20;
    second2->next = second;
  
    cout<<"first list"<<endl;
    printList(head1);
    cout<<"second list"<<endl;
    printList(head2);
    
    findIntersection(head1,head2);
	return 0;
}

void findIntersection(Node* head1, Node* head2){
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    
    while(ptr1!=NULL){
        
        while(ptr2!=NULL){
            if(ptr2->data == ptr1->data){
                cout<<"intersection found at "<<ptr2->data<<endl;
                return;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }
}
