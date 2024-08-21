#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of items purchased: ");
    scanf("%d", &n);
    char items[n][128];
    int quantity[n];
    float price[n], amt[n], total_amt = 0;
    for(int i = 0; i < n; i++){
        printf("\nItem %d\n", i + 1);
        printf("Name of the item: ");
        scanf("%s", items[i]);
        printf("Quantity: ");
        scanf("%d", &quantity[i]);
        printf("Price per unit: ");
        scanf("%f", &price[i]);
        amt[i] = quantity[i] * price[i];
        total_amt += amt[i];
    }
    printf("\n**************************************** BILL ****************************************\n");
    printf("Item\t\tQuantity\tPrice\t\tAmount\n");
    printf("--------------------------------------------------------------------------------------\n");
    for(int  i = 0; i < n; i++)
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", items[i], quantity[i], price[i], amt[i]);
    printf("--------------------------------------------------------------------------------------\n");
    printf("Total Amount to be paid: %.2f\n", total_amt);
    printf("--------------------------------------------------------------------------------------\n");
    return 0;
}
