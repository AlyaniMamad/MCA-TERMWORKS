/*Write a program to implement priority queue using linked list.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

Node *create(int data, int priority)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

void enqueue(Node **head, int data, int priority)
{
    Node *newNode = create(data, priority);

    if (*head == NULL || priority > (*head)->priority)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(Node **head)
{
    if (*head == NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    Node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

void printQueue(Node *head)
{
    printf("Priority Queue: ");
    while (head != NULL)
    {
        printf("(%d, %d) ", head->data, head->priority);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;

    int data, priority, choice;
    do
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print queue\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(&head, data, priority);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            printQueue(head);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
