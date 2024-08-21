#include <stdio.h>
#include <limits.h>
#define PI 3.14159265358

double cosine(double x){
    double cosx = 1, xn = 1, xfac = 1;
    int i = 1;
    while(x > 2*PI)
        x -= 2*PI;
    while(x < -2*PI)
        x += 2*PI;
    while(i <= 32){
        xfac *= i;
        xn *= x;
        if(i % 2 == 0){
            if(i % 4 == 0)
                cosx += xn / xfac;
            else
                cosx -= xn / xfac;
        }
        i++;
    }
    return cosx;
}

double sine(double x){
    return cosine(PI/2 - x);
}

double tangent(double x){
    return sine(x) / cosine(x);
}

double sine_inverse(double x) {
    // if (x < -1 || x > 1) {
    //     printf("Out of domain\n");
    //     return NAN;
    // }

    double sum = 0.0;
    double term = x;
    double x_squared = x * x;
    int n;

    // Maclaurin series approximation for asin(x)
    for (n = 1; n <= 10; n++) {
        double factor = (2.0 * n - 1.0) / (2.0 * n);
        term *= x_squared * factor / (n * (2.0 * n + 1.0));
        sum += term;
    }
    return x + sum;
}

double cosine_inverse(double x){
    return PI/2 - sine_inverse(x);
}

int main() {
    double x, cosx, sinx, tanx, asinx, acosx;
    scanf("%lf", &x);
    cosx = cosine(x);
    sinx = sine(x);
    tanx = tangent(x);
    asinx = sine_inverse(x);
    acosx = cosine_inverse(x);
    printf("cos(%lf) = %lf\n", x, cosx);
    printf("sin(%lf) = %lf\n", x, sinx);
    printf("tan(%lf) = %lf\n", x, tanx);
    printf("sin^-1(sin(%lf)) = %lf\n", x, asinx);
    printf("cos^-1(cos(%lf)) = %lf\n", x, acosx);
    return 0;
}