#include <stdio.h>
#include <math.h>

float f(float x) {
    return log(x) - cos(x);  
}

float f_prime(float x) {
    return 1/x + sin(x);     
}

int main() {
    float x0, x1, tol;
    int max_iter, i;

    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerance: ");
    scanf("%f", &tol);
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);

    printf("\nIter\t   x0\t\t f(x0)\t\t f'(x0)\t\t x1\n");
    printf("---------------------------------------------------------------\n");

    for(i = 1; i <= max_iter; i++) {
        double fx = f(x0);
        double fpx = f_prime(x0);
        x1 = x0 - fx/fpx;  

        printf("%2d\t%10.6f\t%10.6f\t%10.6f\t%10.6f\n", i, x0, fx, fpx, x1);

        if(fabs(x1 - x0) < tol) {
            printf("\nConverged to root: %lf after %d iterations\n", x1, i);
            break;
        }
        x0 = x1;
    }

    if(i > max_iter) {
        printf("\nDid not converge after %d iterations.\n", max_iter);
    }

    return 0;
}
