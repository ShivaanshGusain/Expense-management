#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filterByCategory.h"

void filterByCategory() {
FILE *file;
    getchar();
    char filename[] = "../data/expenses.txt";
    char line1[100], line2[100], line3[100],line4[100], line5[100];
    char targetCategory[100];
    
    printf("Enter the category to search: ");
    fgets(targetCategory, 100, stdin);
    targetCategory[strcspn(targetCategory, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fgets(line1, sizeof(line1), file);

    while (fgets(line1, 100, file) != NULL &&
           fgets(line2, 100, file) != NULL &&
           fgets(line3, 100, file) != NULL &&
           fgets(line4, 100, file) != NULL )
        {
        char *colon = strchr(line2, ':');
        if (colon != NULL) {
            char *categoryValue = colon + 1;
            while (*categoryValue == ' ') categoryValue++;
            categoryValue[strcspn(categoryValue, "\n")] = '\0';

            if (strcmp(categoryValue, targetCategory) == 0) {
                printf("\n%s%s\n%s%s\n", line1, line2, line3, line4);
            }
        }

        char temp[100];
        fgets(temp, 100, file);
    }
    fclose(file);
}