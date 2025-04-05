#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int productCount;
} Bill;

void addProduct(Bill *bill) {
    if (bill->productCount >= MAX_PRODUCTS) {
        printf("Cannot add more products. Maximum limit reached.\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    bill->products[bill->productCount] = newProduct;
    bill->productCount++;
    printf("Product added successfully!\n");
}

float calculateTotal(Bill *bill) {
    float total = 0.0;
    for (int i = 0; i < bill->productCount; i++) {
        total += bill->products[i].price * bill->products[i].quantity;
    }
    return total;
}

void printBill(Bill *bill) {
    printf("\n--- Invoice ---\n");
    for (int i = 0; i < bill->productCount; i++) {
        printf("%s (x%d): $%.2f\n", bill->products[i].name, bill->products[i].quantity, 
               bill->products[i].price * bill->products[i].quantity);
    }
    printf("Total: $%.2f\n", calculateTotal(bill));
    printf("----------------\n");
}

int main() {
    Bill bill;
    bill.productCount = 0;
    int choice;

    do {
        printf("\nBilling Application\n");
        printf("1. Add Product\n");
        printf("2. Print Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&bill);
                break;
            case 2:
                printBill(&bill);
                break;
            case 3:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}