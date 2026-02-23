#include <stdio.h>

struct Student {
    char name[50];
    float marks;
};

int main() {
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input student details
    for(i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }

    // Assume first student has highest marks
    int highestIndex = 0;

    for(i = 1; i < n; i++) {
        if(s[i].marks > s[highestIndex].marks) {
            highestIndex = i;
        }
    }

    // Display result
    printf("\nStudent with highest marks:\n");
    printf("Name: %s\n", s[highestIndex].name);
    printf("Marks: %.2f\n", s[highestIndex].marks);

    return 0;
}

