#ifndef ADDEXPENSE_H
#define ADDEXPENSE_H

typedef struct {
    char name[50];
    char category[30];
    float amount;
    char date[20];
} Expense;

extern Expense* expenses;
extern int expenseCount;

void addExpense();

#endif
