#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to Create Node
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
//Creating a List, Inserting Nodes Front, Middle, End
void CreateListNoNodes();
//head refers to the entry point in a linked list, aka the first node. 
NODE* CreateListNode(NODE* new, char* firstName, char* lastName, char* PUID, int Age);
NODE* InsertFront(NODE* head, NODE* new);
void InsertMiddle(NODE** head, NODE* new, int index);
void InsertEnd(NODE** head, NODE* new);
//Deleting Nodes Front, Middle, End
void DeleteFront(NODE** head);
void DeleteMiddle(NODE** head, int index);
void DeleteEnd(NODE** head);
//Traversing the list based on values and Search for PUID
void Traverse(NODE* head);
void Search(NODE* head, int index);
//Declared Functions



int main()
{
    commands();// Holds the menu loop & Switch Case.  
    return 0;
}

void menu()
{
    //function to list menu
    printf("1. Create a List with no nodes, just a start pointer\n"
    "2. Create a list with a single node\n"
    "3. Insert a node at the front of the list\n"
    "4. Insert a node in the middle of the of the list\n"
    "5. Insert a node at the end of the of the list\n"
    "6. Delete the first node in the list\n"
    "7. Delete a node in the middle of the list\n"
    "8. Delete a node at the end of the list\n"
    "9. (N/A) Traverse the list based on some key value in the data portion of the node\n" //Work in Progress... Could not figure out.
    "10.(N/A) Search for a particular node by using PUID of each node. Return -1 if that PUID is not in existence\n" // Work in Progress ... Could not figure out. 
    "11.Exit the program\n\n"
    "Please enter a number: ");

}

int commands()
{
    int input;

    NODE* head = NULL;

    char firstName[25]; //Longer names possible
    char lastName[25]; //Longer names possible

    char PUID[10]; //10 for 10 numeric ID
    int Age = 0;
    
    int index = 0;
    int i = 0; //increment that controls case 2 based off case 1

    //infinite loop to keep asking for menu
    while (1) {
        menu();
        scanf("%d", &input);
       
        switch (input)
        {
        case 1: //CreateListNoNodes
            if (head == NULL)
            {

                CreateListNoNodes(i);
                int i = 1;

            }
            else
            {
                printf("\n\nThere is already a List! \n");
            }

            break;

        case 2: //CreateListNode
            if (i == 0)
            {
                printf("Please Enter a First Name: ");
                scanf("%s", firstName);
                printf("Please Enter a Last name: ");
                scanf("%s", lastName);
                printf("Please Enter a PUID: ");
                scanf("%s", PUID);
                printf("Please Enter an Age: ");
                scanf("%d", &Age);
                printf("\n");
                head = CreateListNode(head, firstName, lastName, PUID, Age);
                printf("The Node has been created:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n", head->firstName, head->lastName, head->PUID, head->Age);
            }
            else
            {
                printf("\n\nThere is already a List! ");
            }

            break;

        case 3: //InsertFront
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
            head = NewNode;
            NewNode = InsertFront(head, NewNode);
            printf("The Node has been created:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n", head->firstName, head->lastName, head->PUID, head->Age);

            break;

        case 4: //InsertMiddle
            printf("Please Enter a First Name: ");
            scanf("%s", firstName);
            printf("Please Enter a Last name: ");
            scanf("%s", lastName);
            printf("Please Enter a PUID: ");
            scanf("%s", PUID);
            printf("Please Enter an Age: ");
            scanf("%d", &Age);
            printf("Please Enter the Index: ");
            scanf("%d", &index);
            printf("\n");
            NODE* NewNode1 = NULL;
            NewNode1 = CreateListNode(NewNode1, firstName, lastName, PUID, Age);
            InsertMiddle(&head, NewNode1, index);
            break;

        case 5: //InsertEnd
            printf("Please Enter a First Name: ");
            scanf("%s", firstName);
            printf("Please Enter a Last name: ");
            scanf("%s", lastName);
            printf("Please Enter a PUID: ");
            scanf("%s", PUID);
            printf("Please Enter an Age: ");
            scanf("%d", &Age);
            NODE* NewNode2 = NULL;
            NewNode2 = CreateListNode(NewNode2, firstName, lastName, PUID, Age);
            InsertEnd(&head, NewNode2);

            break;

        case 6: //DeleteFront
            DeleteFront(&head);
            break;

        case 7: //DeleteMiddle
            printf("Please Enter index: ");
            scanf("%d", &index);
            printf("\n");
            DeleteMiddle(&head, index);

            break;

        case 8: //DeleteEnd
            DeleteEnd(&head);

            break;

        case 9: //traverse would be here. 
            //Traverse(head);
            break;

        case 10: //search would be here. 
            //printf("Please Enter PUID?");
            //scanf()
            //printf()
            //Search()
            break;

        case 11: //exit the Program
            printf("Exiting Program.");
            return 0;
            break;
        }
    }
    return 0;
}

//Create list with no nodes
void CreateListNoNodes() {
    printf("List With No Nodes Created.\n");
 
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

//Insert node in middle
void InsertMiddle(NODE** head, NODE* new, int index) {
    NODE* temp = *head;
    if (index == 0)
    {
        InsertFront(temp, new);
        *head = new;
        printf("The Node has been created:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n", new->firstName, new->lastName, new->PUID, new->Age);
        return;
    }
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Try Another Index.");
            break;
        }
    }
    if (temp != NULL)
    {
        new->next = temp->next;
        temp->next = new;
        printf("The Node has been created:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n", new->firstName, new->lastName, new->PUID, new->Age);
    }
    return;
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

//Delete node in middle
void DeleteMiddle(NODE** head, int index) {
    if (*head == NULL)
    {
        printf("\nList Empty");
        return;
    }
    NODE* delNode = *head;
    NODE* keepNode = *head;
    for (int i = 0; i < index; i++)
    {
        keepNode = delNode;
        delNode = delNode->next;
        if (delNode == NULL)
        {
            printf("Please Try Another Index.");
            break;
        }
    }
    if (delNode != NULL)
    {
        if (delNode == *head)
        {
            *head = (*head)->next;
        }
        keepNode->next = delNode->next;
        delNode->next = NULL;
        printf("\nThe following node has been deleted:\nFirst Name: %s\nLast Name: %s\nPUID: %s\nAge: %d\n ", delNode->firstName, delNode->lastName, delNode->PUID, delNode->Age);

    }
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





