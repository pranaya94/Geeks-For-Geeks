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
    struct Node* fifth = NULL;
    struct Node* sixth = NULL;
    
    first = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));
    fifth = (Node*)malloc(sizeof(Node));
    sixth = (Node*)malloc(sizeof(Node));
    
    first->data = 1;
    first->next = second;
    second->data= 1;
    second->next = third;
    third->data = 1;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = sixth;
    sixth->data = 6;
    sixth->next  = NULL;
    
    
    return(first);
}

void removeDuplicates(Node** head){
  struct Node *p1,*p2,*temp;
  p1 = *head;
  
  while(p1->next!=NULL){
      
      p2 = p1->next;
      
      while(p2!=NULL){
          if(p1->data == p2->data){
              temp = p2;
              p1->next = p2->next;
              free(p2);
              p2 = temp->next;
          }
          else{
              break;
          }
      }
      
      p1 = p1->next;
  }
  return;
}

int main() {
    struct Node* head;
    head = initializeList();
    printList(head);
    removeDuplicates(&head);
    cout<<"Uniques List: "<<endl;
    printList(head);
    
    
	return 0;
} 
