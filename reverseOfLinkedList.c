#include <stdio.h>
#include <stdlib.h>

void createLinkedListNode();
void traverse();

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int main() {
    int option;

    while (1) {
        printf("\nEnter the option\n");
        printf("1. create Node\n");
        printf("2. traverse\n");
        printf("3. reverseLinkedList\n");
        printf("4. exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                createLinkedListNode();
                break;

            case 2:
                traverse();
                break;

            case 3:
                break;

            case 4:
                return 0;

            default:
                printf("Invalid option\n");
                break;
        }
    }
}

void createLinkedListNode() {

    struct node *dataNode = malloc(sizeof(struct node));
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
    } 
    else {
        struct node *trav = head;

        while (trav->next != NULL) {
            trav = trav->next;
        }

        trav->next = dataNode;
    }
}

void traverse() {

    struct node *trav = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    while (trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }

    printf("NULL\n");
}
