#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void createLinkedListNode();
void traverse();
void getTheTotalRelation();
void showHighestPriorityBugs();

struct databaseNode {
    int bugId;
    bool activeStatus;
    char bugpriority[20];
    char bugInfo[20];
    struct databaseNode *next;
};

struct databaseNode *head = NULL;

int main() {
    int option;

    while (1) {
        printf("\nEnter the option\n");
        printf("1. Create Node\n");
        printf("2. Traverse\n");
        printf("3. Count the bugs\n");
        printf("4. Get high priority bugs list\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                createLinkedListNode();
                break;

            case 2:
                traverse();
                break;

            case 3:
                getTheTotalRelation();
                break;

            case 4:
                showHighestPriorityBugs();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid option\n");
                break;
        }
    }
}

void createLinkedListNode() {

    struct databaseNode *dataNode =
        (struct databaseNode *)malloc(sizeof(struct databaseNode));

    char priorityMessage[20] = "";
    char bugInformation[20] = "";
    int bugId;

    if (dataNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the bug ID: ");
    scanf("%d", &bugId);

    printf("Enter the priority: ");
    scanf("%19s", priorityMessage);

    printf("Enter the bug information: ");
    scanf("%19s", bugInformation);

    dataNode->bugId = bugId;
    dataNode->next = NULL;

    strcpy(dataNode->bugpriority, priorityMessage);
    strcpy(dataNode->bugInfo, bugInformation);

    dataNode->activeStatus = true;

    if (head == NULL) {
        head = dataNode;
    }
    else {
        struct databaseNode *trav = head;

        while (trav->next != NULL) {
            trav = trav->next;
        }

        trav->next = dataNode;
    }

    printf("Bug created successfully\n");
}

void traverse() {

    struct databaseNode *trav = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    while (trav != NULL) {
        printf("%d -> ", trav->bugId);
        trav = trav->next;
    }

    printf("NULL\n");
}

void getTheTotalRelation() {

    struct databaseNode *trav = head;
    int bugCount = 0;
    int activeBugCount = 0;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    while (trav != NULL) {

        bugCount = bugCount + 1;

        if (trav->activeStatus == true) {
            activeBugCount = activeBugCount + 1;
        }

        trav = trav->next;
    }

    printf("Total bugs: %d\n", bugCount);
    printf("Active bugs: %d\n", activeBugCount);
}

void showHighestPriorityBugs() {

    struct databaseNode *trav = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    printf("\nHigh priority active bugs:\n");

    while (trav != NULL) {

        if (trav->activeStatus == true &&
            strcmp(trav->bugpriority, "high") == 0) {

            printf("Bug ID: %d\n", trav->bugId);
            printf("Bug Info: %s\n", trav->bugInfo);
        }

        trav = trav->next;
    }
}
