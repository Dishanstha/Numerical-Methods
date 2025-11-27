#include <stdio.h>
#include <math.h>
float f(float x) {
    return x*x*x - x - 2;   
}

int main() {
    float a, b, c;
    int i, n;

    printf("Enter value of a: ");
    scanf("%f", &a);

    printf("Enter value of b: ");
    scanf("%f", &b);

    printf("Enter number of iterations: ");
    scanf("%d", &n);
    if (f(a) * f(b) > 0) {
        printf("Invalid interval! f(a) and f(b) must have opposite signs.\n");
        return 0;
    }

    printf("\nIter\t\ta\tb\tc\tf(c)\n");
    printf("-------------------------------------------------\n");

    for (i = 1; i <= n; i++) {
        c = (a + b) / 2;

        printf("%d\t  %.4f   %.4f   %.4f   %.4f\n",
               i, a, b, c, f(c));

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    printf("\nApproximate Root = %.4f\n", c);

    return 0;
}
