#include <stdio.h>

int main(){
    char item[50];
    float price, shipping, total;
    int overnight;

    printf("Enter the item: ");
    scanf("%s", item);
    printf("Enter the price: ");
    scanf("%f", &price);
    printf("Overnight delivery (0==no, 1==yes): ");
    scanf("%d", &overnight);

    if(price < 100)
        shipping = 20.0;
    else
        shipping = 30.0;

    if(overnight)
        shipping += 50.0;

    total = price + shipping;

    printf("\nInvoice:\n");
    printf("%s: Rs.%.2f\n", item, price);
    printf("Shipping: Rs.%.2f\n", shipping);
    printf("Total: Rs.%.2f\n", total);

    return 0;
}