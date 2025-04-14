#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewExpenses.h"

void viewExpenses() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No expenses found. Please add some expenses first.\n");
        return;
    }

    char line[1024];
    int count = 0;

    printf("\n===== All Expenses =====\n");
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char name[50], category[30], date[20];
        float amount;

        int parsed = sscanf(line, "%49[^,],%29[^,],%f,%19[^\n]", name, category, &amount, date);
        if (parsed == 4) {
            printf("Expense %d:\n", ++count);
            printf("  Name    : %s\n", name);
            printf("  Category: %s\n", category);
            printf("  Amount  : %.2f\n", amount);
            printf("  Date    : %s\n\n", date);
        } else {
            printf("Warning: Skipping malformed line: %s\n", line);
        }
    }

    if (count == 0) {
        printf("No expenses recorded yet.\n");
    }

    fclose(file);
}
