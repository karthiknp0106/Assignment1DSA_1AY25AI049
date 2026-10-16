
#include <stdio.h>

typedef struct {
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b) {
    polynomial c;
    int i;

    c.degree = (a.degree > b.degree) ? a.degree : b.degree;

    for (i = 0; i <= c.degree; i++) {
        int exp = c.degree - i;
        c.coef[i] = 0;

        if (exp <= a.degree)
            c.coef[i] += a.coef[a.degree - exp];

        if (exp <= b.degree)
            c.coef[i] += b.coef[b.degree - exp];
    }

    return c;
}

void display(polynomial p) {
    int i, exp, first = 1;

    for (i = 0; i <= p.degree; i++) {
        exp = p.degree - i;

        if (p.coef[i] == 0)
            continue;

        if (!first)
            printf(p.coef[i] > 0 ? " + " : " - ");
        else if (p.coef[i] < 0)
            printf("-");

        if (p.coef[i] < 0)
            p.coef[i] = -p.coef[i];

        if (exp == 0)
            printf("%.2g", p.coef[i]);
        else if (exp == 1)
            printf("%.2gx", p.coef[i]);
        else
            printf("%.2gx^%d", p.coef[i], exp);

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

void readPoly(polynomial *p) {
    int i;

    printf("Enter degree: ");
    scanf("%d", &p->degree);

    printf("Enter coefficients from x^%d to constant:\n", p->degree);

    for (i = 0; i <= p->degree; i++)
        scanf("%f", &p->coef[i]);
}

int main() {
    polynomial a, b, c;

    printf("First polynomial:\n");
    readPoly(&a);

    printf("Second polynomial:\n");
    readPoly(&b);

    c = add(a, b);

    printf("Sum: ");
    display(c);

    return 0;
}
