#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
void create() {
    struct node *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}
void display() {
    struct node *temp = head;

    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    create();
    display();
    struct node *enode = NULL;
    enode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter newly created node data: ");
    scanf("%d", &enode->data);

    enode->prev = NULL;
    enode->next = head;

    if (head != NULL) {
        head->prev = enode;
    }

    head = enode;

    display();

    return 0;
}
