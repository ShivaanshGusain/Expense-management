#include <stdio.h>
#include <stdbool.h>
#include "addExpense.h"
#include "saveToFile.h"
#include "login.h"
#include "viewExpenses.h"
#include "filterByCategory.h"
#include "calculateMonthlyTotal.h"
int main() {
    if (login()== false) {
        printf("Login failed. Exiting...\n");
        return 1;
    }
    int choice;
    while (choice != 6){
        printf("\n===== Expense Tracker Menu =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Filter by Category\n");
        printf("4. Calculate Monthly Total\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: filterByCategory(); break;
            case 4: calculateMonthlyTotal(); break;
            case 5: saveToFile(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } 

    return 0;
}
