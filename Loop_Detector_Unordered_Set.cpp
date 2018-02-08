#include<bits/stdc++.h>
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

void loopDetector(Node* ptr){
    unordered_set<Node *>s;
   
    while(ptr!=NULL){
      if(s.find(ptr)!=s.end()){ //find returns end iterator if not found
          return; //else returns position of found key
      }
      cout<<ptr->data;
      s.insert(ptr);
      ptr = ptr->next;
    }
}

int main() {
    struct Node* head;
    head = initializeList();
    loopDetector(head);
    
    
	return 0;
}
