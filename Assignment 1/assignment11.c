#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int elem;
    struct Node *next;
} Node;

Node *addIntNode(Node *start, int element)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->elem = element;
    temp->next = NULL;
    if (start != NULL)
    {
        Node *prev = start;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        prev->next = temp;
    }
    else
    {
        start = temp;
    }
    printf("%d has been successfully added.\n", element);
    return start;
}

void printLL(Node *start)
{
    Node *temp = start;
    printf("Start ->");
    while (temp != NULL)
    {
        printf(" %d ->", temp->elem);
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf(" NULL\n");
    }
}

void sort(Node *start)
{
    if (start == NULL)
    {
        return;
    }
    else
    {
        Node *temp = start;
        Node *change = start;
        int min = temp->elem;
        while (temp != NULL)
        {
            if (temp->elem < min)
            {
                min = temp->elem;
                change = temp;
            }
            temp = temp->next;
        }
        change->elem = start->elem;
        start->elem = min;
        temp = start;
        sort(temp->next);
    }
}

int main()
{
    Node *start = NULL;
    int val = 0;
    int n = 0;
    printf("Enter number of integers to be entered in the linked list:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Please enter value to add to list:");
        scanf("%d", &val);
        start = addIntNode(start, val);
    }
    printf("The unsorted list is:\n");
    printLL(start);
    sort(start);
    printf("The sorted list is:\n");
    printLL(start);
}