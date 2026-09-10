#include <stdio.h>
#include <stdlib.h>

void createLinkedListNode();
void traverse();
void reverseLinkedList();
void deleteNodeAtPosition(int pos_no);

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int main() {
    int option, position_number = 0;

    while (1) {
        printf("\nEnter the option\n");
        printf("1. create Node\n");
        printf("2. traverse\n");
        printf("3. delete node at position \n");
        printf("4. exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                createLinkedListNode();
                break;

            case 2:
                traverse();
                break;

            case 3:reverseLinkedList();
                break;

            case 4: printf("Enter the position_no: ");
                    scanf("%d", &position_number);
                    deleteNodeAtPosition(position_number);
                    break;

            default:
                printf("Invalid option\n");
                break;
        }
    }
}

void createLinkedListNode() {
    // static struct node *previousNodeStore = NULL;
    struct node *dataNode = malloc(sizeof(struct node));
    struct node *trav = head;
    int data;

    printf("Enter the data\n");
    scanf("%d", &data);

    if (dataNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    dataNode->data = data;
    dataNode->next = NULL;
    
    if (head == NULL) {
        head = dataNode;
        dataNode -> next = head;
    }else{
        while(trav -> next!= head){
            printf("%d", trav -> data);
            trav = trav -> next;
        }
    }
    
    // previousNodeStore = dataNode;
   
}

void traverse() {

    struct node *trav = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    while (trav != head) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }

    printf("NULL\n");
}

void reverseLinkedList() {
    struct node *prev = NULL;
    struct node *trav = head;
    struct node *next = NULL;

    while (trav != NULL) {
        next = trav->next;
        trav->next = prev;
        prev = trav;
        trav = next;
    }

    head = prev;
}

void deleteNodeAtPosition(int pos_no){
    int count_pos = 0, count_elements = 0;
    struct node *prev = NULL;
    struct node *trav = head;
    struct node *next = NULL;

    while(trav -> next!=head){
        next = trav -> next;
        prev = trav;
        trav = trav -> next;
        count_pos++;
        count_elements++;
        if(count_pos == pos_no){
            trav = trav-> next;
            prev -> next = trav -> next;
            free(trav);
            count_pos = 0;
        }
    }

    if(count_elements > 1){
        deleteNodeAtPosition(pos_no);
    }else{
        printf("%d", trav -> data);
    }
}
