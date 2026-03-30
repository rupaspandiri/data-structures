#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create list
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

// Display list
void display() {
    struct node *temp = head;

    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Delete at position
void deleteAtPosition(int pos) {
    struct node *temp = head;
    int i = 1;

    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }

    // Deleting first node
    if (pos == 1) {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;

        free(temp);
        return;
    }

    // Traverse to position
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nInvalid position.");
        return;
    }

    // Adjust links
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

int main() {
    int pos;

    create();
    display();

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    deleteAtPosition(pos);

    display();

    return 0;
}
