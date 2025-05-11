#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculateMonthlyTotal.h"

void calculateMonthlyTotal() {
    getchar();
    FILE *file;
    char filename[] = "../data/expenses.txt"; 
    char line1[100], line2[100], line3[100], line4[100], line5[100];
    char targetMonth[10];
    int totalAmount = 0;

    printf("Enter the month to search (YYYY-MM): ");
    fgets(targetMonth, sizeof(targetMonth), stdin);
    targetMonth[strcspn(targetMonth, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fgets(line1, sizeof(line1), file);

    while (fgets(line1, sizeof(line1), file) != NULL &&
           fgets(line2, sizeof(line2), file) != NULL &&
           fgets(line3, sizeof(line3), file) != NULL &&
           fgets(line4, sizeof(line4), file) != NULL
           ) {

        char *dateColon = strchr(line4, ': ');
        if (dateColon != NULL) {
            char *dateValue = dateColon + 1;

            while (*dateValue == ' ') dateValue++;

            dateValue[strcspn(dateValue, "\n")] = '\0';

            char text[100] = "Date    : ";
            strcat(text, targetMonth);

            dateValue[strlen(dateValue)-3] = '\0';

            // printf("\n");
            // printf("Date value: '%s'\n", dateValue);
            // printf("Target month: '%s'\n", text);

            if (strcmp(dateValue, text) == 0) {

                // --------- Extract Amount ---------
                char *amountColon = strchr(line3, ':');
                if (amountColon != NULL) {
                    char *amountStr = amountColon + 1;
                    while (*amountStr == ' ') amountStr++;
                    amountStr[strcspn(amountStr, "\n")] = '\0';


                    int amount = atoi(amountStr);  
                    totalAmount += amount;         
                }
            }
        }

        char temp[100];
        fgets(temp, sizeof(temp), file);
    }

    fclose(file);

    printf("Total amount in %s: %d\n", targetMonth, totalAmount);  // Final result
}