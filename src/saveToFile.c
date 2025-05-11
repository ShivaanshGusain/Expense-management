#include <stdio.h>
#include "addExpense.h"

void saveToFile() {
    FILE* file = fopen("../data/expenses.txt", "a");
    if (!file) {
        printf("Failed to open file for saving!\n");
        return;
    }

    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "\nName    :  %s\n Category: %s\n Amount  : %f\n Date    : %s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }

    printf("Expenses saved to file successfully!\n");
    fclose(file);
}
