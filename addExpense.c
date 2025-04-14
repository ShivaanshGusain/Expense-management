#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addExpense.h"

Expense* expenses = NULL;
int expenseCount = 0;

void addExpense() {
    char addMore = 'y';
    while (addMore == 'y' || addMore == 'Y') {
        Expense* newExpense = calloc(1, sizeof(Expense)); 
        if (!newExpense) {
            printf("Memory allocation failed!\n");
            return;
        }

        getchar();

        printf("\nEnter Expense Name: ");
        fgets(newExpense->name, sizeof(newExpense->name), stdin);
        newExpense->name[strcspn(newExpense->name, "\n")] = '\0';

        printf("Enter Category: ");
        fgets(newExpense->category, sizeof(newExpense->category), stdin);
        newExpense->category[strcspn(newExpense->category, "\n")] = '\0';

        printf("Enter Amount: ");
        char amountStr[20];
        fgets(amountStr, sizeof(amountStr), stdin);
        newExpense->amount = strtof(amountStr, NULL); 

        printf("Enter Date (YYYY-MM-DD): ");
        fgets(newExpense->date, sizeof(newExpense->date), stdin);
        newExpense->date[strcspn(newExpense->date, "\n")] = '\0';

        expenseCount++;
        Expense* temp = realloc(expenses, expenseCount * sizeof(Expense));
        if (!temp) {
            printf("Reallocation failed!\n");
            free(newExpense);
            return;
        }
        expenses = temp;
        expenses[expenseCount - 1] = *newExpense;
        free(newExpense);

        printf("Expense added successfully!\n");
        printf("Do you want to add another expense? (y/n): ");
        scanf(" %c", &addMore);
    }
}
