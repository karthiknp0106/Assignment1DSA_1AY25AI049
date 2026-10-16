
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[20];
    float marks;
};

int main() {
    struct Student *ptr, *temp;
    int n, i, add;
    float sum = 0, average;
    int topper = 0;
    char choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter roll, name, marks: ");
        scanf("%d %19s %f",
              &(ptr + i)->roll_no,
              (ptr + i)->name,
              &(ptr + i)->marks);
    }

    do {
        sum = 0;
        topper = 0;

        for (i = 0; i < n; i++) {
            sum += (ptr + i)->marks;

            if ((ptr + i)->marks > (ptr + topper)->marks) {
                topper = i;
            }
        }

        average = sum / n;

        printf("\nAverage marks: %.2f\n", average);
        printf("Topper: %s (Roll %d, Marks %.2f)\n",
               (ptr + topper)->name,
               (ptr + topper)->roll_no,
               (ptr + topper)->marks);

        printf("\nAdd 2 more students? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add = 2;

            temp = (struct Student *)realloc(
                ptr, (n + add) * sizeof(struct Student));

            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                break;
            }

            ptr = temp;

            for (i = n; i < n + add; i++) {
                printf("Enter roll, name, marks: ");
                scanf("%d %19s %f",
                      &(ptr + i)->roll_no,
                      (ptr + i)->name,
                      &(ptr + i)->marks);
            }

            n += add;
        }

    } while (choice == 'y' || choice == 'Y');

    free(ptr);
    ptr = NULL;

    return 0;
}
