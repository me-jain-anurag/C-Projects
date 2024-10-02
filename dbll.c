#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev = third;

    int i = 0;
    struct Node* current = head;
    while (current != NULL)
    {
        printf("Data %d = %d\n", i++, current->data);
        current = current->next;
    }
    printf("NULL\n");

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}