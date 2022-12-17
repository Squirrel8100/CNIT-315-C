/******************************************************************************
Logan Fish
CNIT 315 Lab Section 002 Wednesday 3:30 - 5:20
Lab 6 Stacks and Queues

(NOTES)- Everything works for the most part. 
*Weird Issue when printing Stack & Queue...
with more than one Person the first name is missing for the newly added nodes. 
*Could not figure out how to do Reverse Queue. 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Struct declare
typedef struct node {
    char firstName[20];
    char lastName[20];
    char PUID[10];
    int Age;
    struct node* next;
}NODE;

//Declared Functions
int commands();
void menu();
//
void CreateListNoNodes();
//
NODE* CreateListNode(NODE* new, char* firstName, char* lastName, char* PUID, int Age);
NODE* InsertFront(NODE* head, NODE* new);
//
void InsertEnd(NODE** head, NODE* new);
void DeleteFront(NODE** head);
void DeleteEnd(NODE** head);
//
int main()
{
    commands();
    return 0;
}

void menu()
{
    //function to list menu
    printf("1. POP - delete a node from the stack\n"
    "2. PUSH - add a node to the stack\n"
    "3. ENQUEUE - add a node to the queue\n"
    "4. DEQUEUE -  add a node to the queue\n"
    "5. EMPTY QUEUE - remove all of the nodes from the queue\n"
    "6. EMPTY STACK - remove all of the nodes from the stack\n"
    "7. PRINT QUEUE - print the nodes within the queue\n"
    "8. PRINT STACK - print the nodes within the stack\n"
    "9. (Couldn't figure out) REVERSE QUEUE - reverses the queue\n" 
    "10.Exit the program\n\n"
    "Please enter a number: ");

}


int commands()
{
    int input;
    //
    NODE* head = NULL;
    NODE* head2 = NULL;
    //
    char firstName[20]; //Longer names possible
    char lastName[20]; //Longer names possible
    //
    char PUID[10]; //10 for 10 numeric ID
    int Age = 0;
    //
    int index = 0;
    int i = 0; //increment that controls case 2 based off case 1

    //Initializing stack & queue
    printf("Please enter the first user's information\n");
    printf("Please Enter First Name: ");
    scanf("%s", &firstName);
    printf("Please Enter Last name: ");
    scanf("%s", &lastName);
    printf("Please Enter PUID: ");
    scanf("%d", &PUID);
    printf("Please Enter Age: ");
    scanf("%d", &Age);
    
    //Creating the first node for the STACK
    head = (NODE*)malloc(sizeof(NODE));
    strcpy(head->firstName, firstName);
    strcpy(head->lastName, lastName);
    strcpy(head->PUID, PUID);
    head->Age =Age;
    
    //Creating the first node for the QUEUE
    head2 = (NODE*)malloc(sizeof(NODE));
    strcpy(head2->firstName, firstName);
    strcpy(head2->lastName, lastName);
    strcpy(head2->PUID, PUID);
    head2->Age =Age;
    
    //infinite loop to keep asking for menu
    
    while (1) {
        menu();
        scanf("%d", &input);

        switch (input)
        {
        case 1: //POP
            
            DeleteFront(&head);
            break;

        case 2: //PUSH - add a node to the stack
            printf("Please Enter a First Name: ");
            scanf("%s", firstName);
            printf("Please Enter a Last name: ");
            scanf("%s", lastName);
            printf("Please Enter a PUID: ");
            scanf("%s", PUID);
            printf("Please Enter an Age: ");
            scanf("%d", &Age);
            printf("\n");
            
            NODE* NewNod = NULL;
            NewNod = CreateListNode(NewNod, firstName, lastName, PUID, Age);
            NewNod = InsertFront(head, NewNod);
            head = NewNod;
            printf("The Node has been created:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n", head->firstName, head->lastName, head->PUID, head->Age);
            break;

        case 3: //ENQUEUE - add a node to the queue
            printf("Please Enter a First Name: ");
            scanf("%s", firstName);
            printf("Please Enter a Last name: ");
            scanf("%s", lastName);
            printf("Please Enter a PUID: ");
            scanf("%s", PUID);
            printf("Please Enter an Age: ");
            scanf("%d", &Age);
            printf("\n");
            NODE* NewNode = NULL;
            NewNode = CreateListNode(NewNode, firstName, lastName, PUID, Age);
            InsertEnd(&head2, NewNode);
            break;

        case 4: //DEQUEUE -  add a node to the queue
            DeleteFront(&head2);

            break;

        case 5: //EMPTY QUEUE - remove all of the nodes from the queue
            printf("Deleted all nodes in queue\n");
            head2 = NULL;
            break;


        case 6: //EMPTY STACK - remove all of the nodes from the stack
            printf("Deleted all nodes in stack\n");
            head = NULL;
            break;

        case 7: //PRINT QUEUE - print the nodes within the queue
            if (head2 != NULL)
            {
            printNode(head2);
            printf("\n");
            printf("There are %i node(s) in the queue\n", size(head2));
            break;
            }
            
            else
            {
            printf("There are no nodes in the queue\n");
            break;
            }

        case 8: //PRINT STACK - print the nodes within the stack
            if (head != NULL){
            printNode(head);
            printf("\n");
            printf("There are %i node(s) in the Stack\n", size(head));
            
            break;
            }
            
            else{
                printf("There are no nodes in the stack\n");
                break;
            }

        case 9: //REVERSE QUEUE - reverses the queue
            break;

        case 10: //exit the Program
            printf("Exiting...\n");
            return 0;
            
        }
    }
    return 0;
}

//Create list with no nodes
void CreateListNoNodes() {
    printf("List With a pointer created.\n");
 
}

//Create list with a node
NODE* CreateListNode(NODE* new, char* firstName, char* lastName, char* PUID, int Age){
    new = (NODE*)malloc(sizeof(NODE));
    strcpy(new->firstName, firstName);
    strcpy(new->lastName, lastName);
    strcpy(new->PUID, PUID);
    new->Age = Age;
    new->next = NULL;
    return new;
}

//Insert node in front
NODE* InsertFront(NODE* head, NODE* new) {
    new->next = head;
    return new;
}


//Insert node in end
void InsertEnd(NODE** head, NODE* new) {
    NODE* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    printf("The Node has been created:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n", new->firstName, new->lastName, new->PUID, new->Age);
    return;
}

//Delete node in front
void DeleteFront(NODE** head) {
    if (*head == NULL)
    {
        printf("\nList empty");
        return;
    }
    NODE* temp = (*head)->next;
    printf("\nThis node has been deleted:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n ", (*head)->firstName, (*head)->lastName, (*head)->PUID, (*head)->Age);
    *head = temp;

    return;
}

////Delete node in end
void DeleteEnd(NODE** head) {
    if (*head == NULL)
    {
        printf("\nList Empty!");
        return;
    }
    NODE* delNode = *head;
    NODE* secondNode = *head;
    while (delNode->next != NULL)
    {
        secondNode = delNode;
        delNode = delNode->next;
    }
    if (delNode == *head)
    {
        *head = NULL;
        printf("\nThe following node has been deleted:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n ", delNode->firstName, delNode->lastName, delNode->PUID, delNode->Age);
    }
    else
    {
        secondNode->next = NULL;
        printf("\nThe following node has been deleted:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n ", delNode->firstName, delNode->lastName, delNode->PUID, delNode->Age);
    }

    return;
}

int size(NODE* firstN)
{
    int n = 1; 
    NODE* current = firstN;
    while (current->next != NULL)
    {
        n++;
        current = current->next;
    }
    return n;

}

void printNode(NODE* firstN)
{
    
        
    NODE* current = firstN;
    while (current != NULL)
    {
        printf("\nStudent Full Name- %s %s \nPUID - %d \nAge - %d \n",
        current->firstName, current->lastName, current->PUID, current->Age);
        current = current->next;
    }
}



