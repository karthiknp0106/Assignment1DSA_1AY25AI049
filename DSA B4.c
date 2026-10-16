

#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, value;
} term;

void fast_transpose(term a[], term b[]) {
    int row_terms[MAX] = {0};
    int starting_pos[MAX];
    int i, j, col;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    for (i = 1; i <= a[0].value; i++)
        row_terms[a[i].col]++;

    starting_pos[0] = 1;

    for (i = 1; i < a[0].col; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    printf("\nrow_terms: ");
    for (i = 0; i < a[0].col; i++)
        printf("%d ", row_terms[i]);

    printf("\nstarting_pos: ");
    for (i = 0; i < a[0].col; i++)
        printf("%d ", starting_pos[i]);
    printf("\n");

    for (i = 1; i <= a[0].value; i++) {
        col = a[i].col;
        j = starting_pos[col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

void display(term a[]) {
    int i;

    printf("Row Col Value\n");
    for (i = 0; i <= a[0].value; i++)
        printf("%3d %3d %5d\n",
               a[i].row, a[i].col, a[i].value);
}

int main() {
    int m, n, i, j, count = 0, x;
    int matrix[10][10];
    term a[MAX + 1], b[MAX + 1];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    if (m <= 0 || n <= 0 || m > 10 || n > 10) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    a[0].row = m;
    a[0].col = n;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (matrix[i][j] != 0) {
                count++;
                a[count].row = i;
                a[count].col = j;
                a[count].value = matrix[i][j];
            }

    a[0].value = count;

    printf("\nOriginal triples:\n");
    display(a);

    fast_transpose(a, b);

    printf("\nTransposed triples:\n");
    display(b);

    printf("\nTriples are already in row-major order.\n");

    return 0;
}
