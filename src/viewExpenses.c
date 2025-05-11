#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viewExpenses.h"

void viewExpenses() {
    FILE *file = fopen("../data/expenses.txt", "r");
    if (file == NULL) {
        printf("No expenses found. Please add some expenses first.\n");
        return;
    }

    char line1[100], line2[100], line3[100],line4[100], line5[100];
    int count = 0;

    printf("\n===== All Expenses =====\n");
    while (fgets(line1, 100, file) != NULL &&
        fgets(line2, 100, file) != NULL &&
        fgets(line3, 100, file) != NULL &&
        fgets(line4, 100, file) != NULL &&
        (fgets(line5, 100, file) != NULL || fgets(line5, 100, file) != "\n"))
    {
        printf("%s%s%s%s%s\n", line1, line2, line3, line4, line5);
        count++;
    }
    // while (fgets(name, sizeof(name), file)!=NULL) {
    // //         printf("Expense %d:\n", ++count);
    // //         printf("  Name    : %s\n", name);
    // //         printf("  Category: %s\n", category);
    // //         printf("  Amount  : %.2f\n", amount);
    // //         printf("  Date    : %s\n\n", date);
    // puts(name);
    // }

    if (count == 0) {
        printf("No expenses recorded yet.\n");
    }

    fclose(file);
}
