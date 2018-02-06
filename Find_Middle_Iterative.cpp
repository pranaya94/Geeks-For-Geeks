//find middle element, if even then return n/2 + 1 th element

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

Node* insertAtFront(Node* head,int n){
    struct Node* newPtr;
    newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = n;
    newPtr->next = head;
    head = newPtr;
    
    return(head);
}


Node* insertAtEnd(Node* head,int n){
    struct Node* newPtr;
    struct Node* ptr;
    newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = n;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = newPtr;
    newPtr->next = NULL;
   
    return(head);
}
/* 0 1 2 3 */

Node* insertAfter(Node* head,int n,int x){
    struct Node* newPtr;
    struct Node* ptr;
    struct Node* temp;
    
    newPtr = (Node*)malloc(sizeof(Node));
    newPtr->data = n;
    ptr = head;
    while(ptr!=NULL && ptr->data!=x){
        ptr=ptr->next;
    }
    
    if(ptr!=NULL){
        temp = ptr->next;
        ptr->next = newPtr;
        newPtr->next = temp;
    }else{
        cout<<"Element not found"<<endl;
        return(head);
    }
    
    return(head);
}

// Node* swapXY(Node* head, int x, int y){
 
//     /*look for nodes*/
//     struct Node* ptrX;
//     struct Node* ptrY;
//     struct Node* prevX;
//     struct Node* prevY;
//     ptrX = head;
//     prevX = head;
//     ptrY = head;
//     prevY = head;
//     int foundX = 0, foundY = 0, posX = 0, posY = 0;
//     while(ptrX!=NULL){
//         if(ptrX->data == x){
//             foundX = 1;
//             break;
//         }
//         prevX = ptrX;
//         ptrX = ptrX->next;
//         posX++;
//     }
//     cout<<endl<<"X position "<<posX<<endl;
    
//     while(ptrY!=NULL){
//             if(ptrY->data == y){
//                 foundY = 1;
//                 break;
//             }
//         prevY = ptrY;
//         ptrY = ptrY->next;
//         posY++;
//     }
//     cout<<endl<<"Y position "<<posY<<endl;
    
//     if(foundX == 0 || foundY == 0){
//         cout<<"nodes not found"<<endl;
//         return(head);
//     }
    
//     struct Node* temp;
//     temp = NULL;
//     /* X and Y adjacent*/
//     if(posX - posY < 0){
//         if(ptrX == head){
//             head = ptrY;
//         }
//         ptrX->next = ptrY->next;
//         ptrY->next = ptrX;
//         prevX->next = ptrY;
//         return(head);
//     }else if(posX - posY > 0){
//         if(ptrY == head){
//             head = ptrX;
//         }
//         ptrY->next = ptrX->next;
//         ptrX->next = ptrY;
//         prevY->next = ptrX;
//         return(head);
//     }
    
// }

int getMiddle(Node* head){
    
    struct Node* ptrSlow;
    struct Node* ptrFast;
    
    ptrSlow = head;
    ptrFast = head;
    
    while(ptrFast->next != NULL && (ptrFast->next)->next != NULL){
        ptrSlow = ptrSlow->next;
        ptrFast = (ptrFast->next)->next;
    }
    
    if(ptrFast->next==NULL){
    return(ptrSlow->data);
    }else if((ptrFast->next)->next == NULL){
    return((ptrSlow->next)->data);
    }
}

int main() {
    struct Node* head;
    bool found = false;
    
    head = initializeList();
    printList(head);
    cout<<"Inserting element at front ****************"<<endl;
    head = insertAtFront(head,0);
    printList(head);
    cout<<"Inserting element at end ****************"<<endl;
    head = insertAtEnd(head,4);
    printList(head);
    cout<<"Inserting element after ****************"<<endl;
    head = insertAfter(head,9,4);
    printList(head);

    int x;
    x = getMiddle(head);
    cout<<endl<<"Middle element is "<<x;
   
    
    
	return 0;
}
