#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Example create function
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

// Display function
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

    // Delete first node
    struct node *temp;

    if (head == NULL) {
        printf("\nList is empty, nothing to delete.");
    } else {
        temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(temp);
    }

    display();

    return 0;
}
