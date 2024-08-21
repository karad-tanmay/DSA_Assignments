#include <stdio.h>

int main() {
    int angle1, angle2, angle3;
    printf("Enter three angles of a triangle: ");
    scanf("%d %d %d", &angle1, &angle2, &angle3);

    if(angle1 == 180 || angle2 == 180 || angle3 == 180)
        printf("Triangle is not valid\n");
    else if(angle1 + angle2 == 180 || angle2 + angle3 == 180 || angle1 + angle3 == 180)
        printf("Triangle is not valid\n");
    else if (angle1 + angle2 + angle3 == 180)
        printf("Triangle is valid\n");
    else
        printf("Triangle is not valid\n");

    return 0;
}
