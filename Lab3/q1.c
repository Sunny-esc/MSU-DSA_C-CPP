#include<stdio.h>
#include<conio.h>
// Define structure for a node in the singly linked list
struct Node {
    int data; // data to store
    struct Node* next; // pointer to the next node
};
// Global pointer to the head of the list
struct Node* head = NULL;
// Function declarations
void insertAtBeginning(int val);
void insertAtEnd(int val);
void DeleteatBeg();
void DeleteatEnd();
void display();



int main() {
    int i,n,d;
    printf("-------------- welcome to Linked list ------------\n");

    printf("Press 1 Insert at beginning\n");
    printf("Press 2 Insert at End\n");
    printf("Press 3 Delete at beginning\n");
    printf("Press 4 Delete at End\n");

    scanf("%d",&n);
     int j,x;
    switch(n){
    case 1:
            printf("how many digit u want to add :\n");
            scanf("%d",&i);

            for(x=0;x<i;x++){
            printf("Enter the digit :\n");
            scanf("%d",&i);
            insertAtBeginning(i);}
           display();
           break;
    case 2:

            printf("how many digit u want to add at end :\n");
            scanf("%d",&j);
            int x;
            for(x=0;x<j;x++){
            printf("Enter the digit :\n");
            scanf("%d",&j);
            insertAtEnd(j);
            }
            display();
            break;
    case 3:
            DeleteatBeg();
            display();
            break;
    case 4:
            DeleteatEnd();
            display();
            break;
    }

 return 0;
}

void display() {
    if (head == NULL) {
    printf("List is empty.\n");
    return;
 }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert a new node at the beginning
void insertAtBeginning(int val) {
 // Allocate memory for new node
 struct Node* newNode = (struct Node*)malloc(sizeof(struct
Node));
 newNode->data = val; // set data
 newNode->next = head; // new node points to current head
 head = newNode; // head is updated to new node
}
// Insert a new node at the end
void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
 // If list is empty, new node becomes head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to the end of the list
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Link last node to new node
}
void DeleteatBeg(){
    if(head== NULL){
        printf("The list is empty\n");
        return;
    }
    struct Node* temp=head; // store current head in tem
    head= head->next;// move head to next node
    free(temp);// delete old head
    printf("Deleted from Beginning \n");
};
void DeleteatEnd(){
    if(head == NULL){
        printf("the list is empty \n");
        return;
    }

    // if there only one node
    else if(head->next == NULL ){
        free(head);
        head=NULL;
        printf("Deleted last Node \n");}
}
