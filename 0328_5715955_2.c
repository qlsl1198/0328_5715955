#include <stdio.h>
#define MAX_DEGREE 101

typedef struct polynomial {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial a = { 6, {7.0, 0.0, 0.0, 5.0, 9.0, 0.0, 1.0} };
polynomial b = { 3, {5.0, 2.0, 1.0, 10.0} };

void print_polynomial(polynomial p);
polynomial multiply_polynomial(polynomial A, polynomial B);

int main() {
    polynomial pp;
    printf("A : ");
    print_polynomial(a);
    printf("B : ");
    print_polynomial(b);
    printf("-----------------------------------------------------------------------\n");

    pp = multiply_polynomial(a, b);
    printf("multiply A and b : ");
    print_polynomial(pp);

    return 0;
}

polynomial multiply_polynomial(polynomial A, polynomial B) {
    polynomial C;
    C.degree = A.degree + B.degree;

    for (int i = 0; i <= A.degree; i++) {
        for (int j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j];
        }
    }

    return C;
}

void print_polynomial(polynomial p) {
    for (int i = p.degree; i > 0; i--) {
        printf("%3.1fx^%d +", p.coef[p.degree - i], i);
    }
    printf("%3.1f\n", p.coef[p.degree]);
}
