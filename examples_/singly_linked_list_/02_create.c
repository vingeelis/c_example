#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* 
 * Functions to create and display list
 */
void createList(int n);
void traverseList();

int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);

    traverseList();

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if (head == NULL)
    {
        printf("Unable to allocate memory");
        exit(0);
    }

    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    // Create n - 1 nodes and add to list
    temp = head; // temp as role of privious node
    for (i = 2; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        // If memory is not allocated for newMode
        if (newNode == NULL)
        {
            printf("Unable to allocate memory");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
}

/*
 * Display entire list
 */
void traverseList()
{
    // Return if list is empty
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    printf("\nData in the list\n");
    // temp = head;
    // while (temp != NULL)
    // {
    //     printf("Data = %d\n", temp->data);
    //     temp = temp->next; // Move to next node
    // }
    for (struct node *temp = head; temp != NULL;)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next; // Move to next node
    }
}