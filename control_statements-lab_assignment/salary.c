#include <stdio.h>
#define HRA 0.10 //in percentage
#define TA 0.05 //in percentage

int main() {
    float basic_pay, hra, ta, total_salary;
    printf("Enter basic pay: ");
    scanf("%f", &basic_pay);
    hra = HRA * basic_pay;
    ta = TA * basic_pay;
    total_salary = basic_pay + hra + ta;
    printf("HRA: %.2f\n", hra);
    printf("TA: %.2f\n", ta);
    printf("Total Salary: %.2f\n", total_salary);
    return 0;
}
