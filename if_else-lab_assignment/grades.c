#include <stdio.h>

int main() {
    float physics, chemistry, biology, mathematics, computer, percentage;
    char grade;

    printf("Enter marks for Physics, Chemistry, Biology, Mathematics, and Computer: ");
    scanf("%f %f %f %f %f", &physics, &chemistry, &biology, &mathematics, &computer);

    percentage = (physics + chemistry + biology + mathematics + computer) / 5;

    if (percentage >= 90)
        grade = 'A';
    else if (percentage >= 80)
        grade = 'B';
    else if (percentage >= 70)
        grade = 'C';
    else if (percentage >= 60)
        grade = 'D';
    else if (percentage >= 40)
        grade = 'E';
    else
        grade = 'F';

    printf("Percentage = %.2f\nGrade = %c\n", percentage, grade);

    return 0;
}
