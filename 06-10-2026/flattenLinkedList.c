// array of linked lists first nodes needs to be printed after deleting of their sub child nodes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

void createNode(Node* startNode);
void createChildOrSubChildNodeForParent(
    int parentNodePosNo,
    Node* startNode,
    bool addChidNodeOrNot
);
void traverseTheLinkedList(Node* startNode);
void flatLinkedList(Node* startNode);

struct Node {
    int data;
    Node* previous;
    Node* subChildNode;
    Node* next;
    bool is_having_sub_nodes_or_not;
};

Node* parentHeadNode = NULL;

int main()
{
    int option, parentPosNo;

    while (1) {

        printf("\nEnter the option:\n"
               "1. To Create Node\n"
               "2. Create Child Nodes For Parent Node\n"
               "3. Display the entire list\n"
               "4. Flatten The Linked List\n"
               "5. Exit\n");

        scanf("%d", &option);

        switch (option) {

            case 1:
                createNode(parentHeadNode);
                break;

            case 2:
                printf("Enter the Parent Node Number: ");
                scanf("%d", &parentPosNo);

                createChildOrSubChildNodeForParent(
                    parentPosNo,
                    parentHeadNode,
                    true
                );
                break;

            case 3:
                traverseTheLinkedList(parentHeadNode);
                break;

            case 4:
                flatLinkedList(parentHeadNode);

                printf("\nList after flattening:\n");
                traverseTheLinkedList(parentHeadNode);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

void createNode(Node* startNode)
{
    Node* dataNode = malloc(sizeof(Node));
    int data = 0;

    if (dataNode == NULL) {
        printf("No dataNode was created\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &data);

    dataNode->data = data;
    dataNode->previous = NULL;
    dataNode->subChildNode = NULL;
    dataNode->next = NULL;
    dataNode->is_having_sub_nodes_or_not = false;

    if (parentHeadNode == NULL) {
        parentHeadNode = dataNode;
        return;
    }

    Node* trav = parentHeadNode;

    while (trav->next != NULL) {
        trav = trav->next;
    }

    trav->next = dataNode;
    dataNode->previous = trav;
}

void createChildOrSubChildNodeForParent(
    int parentNodePosNo,
    Node* startNode,
    bool addChidNodeOrNot
)
{
    Node* trav = startNode;

    int childDataNodeValue;
    int addSubChildOrNot;
    int growChildNodesOnly;

    while (parentNodePosNo > 0 && trav != NULL) {
        trav = trav->next;
        parentNodePosNo--;
    }

    if (trav == NULL) {
        printf("Parent node does not exist\n");
        return;
    }

    if (addChidNodeOrNot) {

        Node* childDataNode = malloc(sizeof(Node));

        if (childDataNode == NULL) {
            printf("Unable to create child node\n");
            return;
        }

        printf("Enter the child node data value: ");
        scanf("%d", &childDataNodeValue);

        childDataNode->data = childDataNodeValue;
        childDataNode->previous = NULL;
        childDataNode->next = NULL;
        childDataNode->subChildNode = NULL;
        childDataNode->is_having_sub_nodes_or_not = false;

        if (trav->subChildNode == NULL) {
            trav->subChildNode = childDataNode;
            childDataNode->previous = trav;
        }
        else {

            Node* childTrav = trav->subChildNode;

            while (childTrav->next != NULL) {
                childTrav = childTrav->next;
            }

            childTrav->next = childDataNode;
            childDataNode->previous = childTrav;
        }

        trav->is_having_sub_nodes_or_not = true;

        printf(
            "Do you want to add sub-child node for node %d? (1/0): ",
            childDataNode->data
        );

        scanf("%d", &addSubChildOrNot);

        if (addSubChildOrNot) {
            createChildOrSubChildNodeForParent(
                0,
                childDataNode,
                true
            );
        }

        printf(
            "Do you want to grow child nodes linked list? (1/0): "
        );

        scanf("%d", &growChildNodesOnly);

        if (growChildNodesOnly) {
            createChildOrSubChildNodeForParent(
                parentNodePosNo,
                startNode,
                true
            );
        }
    }
}

void traverseTheLinkedList(Node* startNode)
{
    Node* trav = startNode;

    while (trav != NULL) {

        printf("%d <-> ", trav->data);

        Node* child = trav->subChildNode;

        while (child != NULL) {

            printf("├── %d\n", child->data);

            Node* subChild = child->subChildNode;

            while (subChild != NULL) {
                printf("│   ├── %d\n", subChild->data);
                subChild = subChild->next;
            }

            child = child->next;
        }

        trav = trav->next;
    }
}

Node* flattenChildren(Node* child)
{
    Node* current = child;
    Node* tail = NULL;

    while (current != NULL) {

        Node* nextSibling = current->next;

        if (current->subChildNode != NULL) {

            Node* childHead = current->subChildNode;

            Node* childTail = flattenChildren(childHead);

            current->next = childHead;
            childHead->previous = current;

            childTail->next = nextSibling;

            if (nextSibling != NULL) {
                nextSibling->previous = childTail;
            }

            current->subChildNode = NULL;
            current->is_having_sub_nodes_or_not = false;

            tail = childTail;
        }
        else {
            tail = current;
        }

        current = nextSibling;
    }

    return tail;
}

void flatLinkedList(Node* startNode)
{
    Node* trav = startNode;

    while (trav != NULL) {

        Node* nextParent = trav->next;

        if (trav->subChildNode != NULL) {

            Node* childHead = trav->subChildNode;

            Node* childTail = flattenChildren(childHead);

            trav->next = childHead;
            childHead->previous = trav;

            childTail->next = nextParent;

            if (nextParent != NULL) {
                nextParent->previous = childTail;
            }

            trav->subChildNode = NULL;
            trav->is_having_sub_nodes_or_not = false;
        }

        trav = nextParent;
    }
}


// claude approach 
// Multilevel doubly linked list:
//  - create parent nodes, add children / sub-children to any parent
//  - display the whole structure as a tree
//  - flatten the list (children spliced in after their parent)
//  - delete all sub-nodes so only the parent list remains
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node* previous;   // previous sibling on the same level (NULL for first)
    Node* next;       // next sibling on the same level
    Node* child;      // head of this node's child list
};

/* ---------- input helpers ---------- */

// Reads an int, re-prompting on bad input. Returns 0 on EOF.
static int readInt(const char* prompt, int* out)
{
    for (;;) {
        printf("%s", prompt);

        int result = scanf("%d", out);
        if (result == 1) {
            return 1;
        }
        if (result == EOF) {
            return 0;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // discard the rest of the bad line
        }
        printf("Please enter a number.\n");
    }
}

static int askYesNo(const char* prompt)
{
    int answer;
    if (!readInt(prompt, &answer)) {
        return 0;
    }
    return answer != 0;
}

/* ---------- list logic (no I/O) ---------- */

static Node* newNode(int data)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->previous = NULL;
    node->next = NULL;
    node->child = NULL;
    return node;
}

static void appendSibling(Node** head, Node* node)
{
    if (*head == NULL) {
        *head = node;
        return;
    }

    Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = node;
    node->previous = tail;
}

// position is 1-based
static Node* findByPosition(Node* head, int position)
{
    while (head != NULL && position > 1) {
        head = head->next;
        position--;
    }
    return (position == 1) ? head : NULL;
}

static Node* addChild(Node* parent, int value)
{
    Node* node = newNode(value);
    if (node != NULL) {
        appendSibling(&parent->child, node);
    }
    return node;
}

// Splices every child list in right after its parent, at all depths.
// Returns the last node of the resulting list.
static Node* flatten(Node* head)
{
    Node* current = head;
    Node* tail = head;

    while (current != NULL) {
        Node* next = current->next;

        if (current->child != NULL) {
            Node* childHead = current->child;
            Node* childTail = flatten(childHead);

            current->child = NULL;
            current->next = childHead;
            childHead->previous = current;

            childTail->next = next;
            if (next != NULL) {
                next->previous = childTail;
            }

            tail = childTail;
        }
        else {
            tail = current;
        }

        current = next;
    }

    return tail;
}

// Frees a list and everything below it.
static void freeList(Node* head)
{
    while (head != NULL) {
        Node* next = head->next;
        freeList(head->child);
        free(head);
        head = next;
    }
}

// Removes every sub-node at every depth, keeping only the parent list.
static void deleteSubNodes(Node* head)
{
    for (Node* node = head; node != NULL; node = node->next) {
        freeList(node->child);
        node->child = NULL;
    }
}

/* ---------- display ---------- */

static void printTree(const Node* head, int depth)
{
    for (const Node* node = head; node != NULL; node = node->next) {
        if (depth == 0) {
            printf("%d\n", node->data);
        }
        else {
            printf("%*s├── %d\n", (depth - 1) * 4, "", node->data);
        }
        printTree(node->child, depth + 1);
    }
}

static void printList(const Node* head)
{
    if (head == NULL) {
        printf("(list is empty)\n");
        return;
    }
    printTree(head, 0);
}

// Prints the list level by level as "a <-> b <-> c <-> NULL"
static void printFlat(const Node* head)
{
    if (head == NULL) {
        printf("(list is empty)\n");
        return;
    }
    for (const Node* node = head; node != NULL; node = node->next) {
        printf("%d <-> ", node->data);
    }
    printf("NULL\n");
}

/* ---------- interactive parts ---------- */

static void addChildrenInteractive(Node* parent)
{
    do {
        int value;
        if (!readInt("Enter the child node value: ", &value)) {
            return;
        }

        Node* child = addChild(parent, value);
        if (child == NULL) {
            printf("Out of memory, child not created\n");
            return;
        }

        char prompt[96];
        snprintf(prompt, sizeof(prompt),
                 "Add sub-children under %d? (1/0): ", child->data);
        if (askYesNo(prompt)) {
            addChildrenInteractive(child);
        }
    } while (askYesNo("Add another child to the same parent? (1/0): "));
}

static void createParent(Node** head)
{
    int value;
    if (!readInt("Enter the data: ", &value)) {
        return;
    }

    Node* node = newNode(value);
    if (node == NULL) {
        printf("Out of memory, node not created\n");
        return;
    }
    appendSibling(head, node);
}

int main(void)
{
    Node* head = NULL;

    for (;;) {
        printf("\nEnter the option:\n"
               "1. Create parent node\n"
               "2. Add child nodes to a parent\n"
               "3. Display the entire list\n"
               "4. Flatten the list\n"
               "5. Delete all sub-nodes (keep parents only)\n"
               "6. Exit\n");

        int option;
        if (!readInt("> ", &option)) {
            break;
        }

        switch (option) {
            case 1:
                createParent(&head);
                break;

            case 2: {
                int position;
                if (!readInt("Enter the parent node number (1 = first): ", &position)) {
                    break;
                }
                Node* parent = findByPosition(head, position);
                if (parent == NULL) {
                    printf("Parent node does not exist\n");
                    break;
                }
                addChildrenInteractive(parent);
                break;
            }

            case 3:
                printList(head);
                break;

            case 4:
                if (head != NULL) {
                    flatten(head);
                }
                printf("\nList after flattening:\n");
                printFlat(head);
                break;

            case 5:
                deleteSubNodes(head);
                printf("\nParent nodes after deleting sub-nodes:\n");
                printFlat(head);
                break;

            case 6:
                freeList(head);
                return 0;

            default:
                printf("Invalid option\n");
        }
    }

    freeList(head);
    return 0;
}