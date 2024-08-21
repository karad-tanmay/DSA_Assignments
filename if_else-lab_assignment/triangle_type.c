#include <stdio.h>

int main() {
    int side1, side2, side3;
    printf("Enter three sides of a triangle: ");
    scanf("%d %d %d", &side1, &side2, &side3);

    if (side1 == side2 && side2 == side3)
        printf("Triangle is Equilateral\n");
    else if (side1 == side2 || side2 == side3 || side1 == side3)
        printf("Triangle is Isosceles\n");
    else
        printf("Triangle is Scalene\n");

    return 0;
}
