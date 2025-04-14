#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculateMonthlyTotal.h"

void calculateMonthlyTotal() {
    char monthInput[8],x[10]; 
    gets(x);
    printf("Enter month to calculate total (format: YYYY-MM): ");
    fgets(monthInput, sizeof(monthInput), stdin);
    monthInput[strcspn(monthInput, "\n")] = '\0';

    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("Could not open expenses.txt\n");
        return;
    }

    char line[200];
    float total = 0.0;
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char name[50], category[30], date[20];
        float amount;

        if (sscanf(line, "%49[^,],%29[^,],%f,%19[^\n]", name, category, &amount, date) == 4) {
            if (strncmp(date, monthInput, 7) == 0) { 
                total += amount;
                found = 1;
            }
        }
    }

    if (found) {
        printf("Total expenses for %s: %.2f\n", monthInput, total);
    } else {
        printf("No expenses found for %s.\n", monthInput);
    }

    fclose(file);
}
