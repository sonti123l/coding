#include<stdio.h>
#include<stdlib.h>

void createNode();
void detectLoop();
void createLoop(int position);

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
int count = 0;
struct node *lastNode = NULL;
int option;

int main(){
    
    int position;
    
    while(1){
        printf("Enter the option: ");
        scanf("%d", &option);
        switch(option){
            
            case 1: createNode();
                    break;
            case 2: detectLoop();
                    break;
            case 3: printf("Enter the position: ");
                    scanf("%d", &position);
                    createLoop(position);
                    break;
                    
            default: exit(0);
        }
    }
}

void createNode(){
    
    struct node *trav = head;
    int data;
    struct node *dataNode = malloc(sizeof(struct node));
    
    if(dataNode != NULL){
        printf("Enter the data: ");
        scanf("%d", &data);
        dataNode -> data = data;
        dataNode -> next = NULL;
        count++;
    }
    
    if(head == NULL){
        head = dataNode;
    }else{
       lastNode -> next = dataNode;
    }
    
    lastNode = dataNode;
}

void createLoop(int position) {
    if (head == NULL) {
        return;
    }

    struct node *trav = head;
    int i = 1;

    while (trav != NULL && i < position) {
        trav = trav->next;
        i++;
    }

    if (trav != NULL) {
        lastNode->next = trav;
    }
}

void detectLoop() {
    struct node *trav = head;
    int current_position = 0;

    while(lastNode -> next != trav) {
      trav = trav -> next;
      current_position++;
    }

    if(current_position == count){

        printf("No loop detected");
    }else{

        printf("loop detected");
    }
    
    exit(0);
}