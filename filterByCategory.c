#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filterByCategory.h"

void filterByCategory() {
    char categoryInput[30],x[10];
    gets(x);
    printf("Enter category to filter: ");
    fgets(categoryInput, sizeof(categoryInput), stdin);
    categoryInput[strcspn(categoryInput, "\n")] = '\0';

    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("Could not open expenses.txt\n");
        return;
    }

    char line[200];
    int found = 0;
    printf("\nExpenses in category '%s':\n", categoryInput);
    while (fgets(line, sizeof(line), file)) {
        char name[50], category[30], date[20];
        float amount;

        if (sscanf(line, "%49[^,],%29[^,],%f,%19[^\n]", name, category, &amount, date) == 4) {
            if (strcasecmp(category, categoryInput) == 0) {
                printf("Name: %s | Category: %s | Amount: %.2f | Date: %s\n", name, category, amount, date);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No expenses found in category '%s'.\n", categoryInput);
    }

    fclose(file);
}
