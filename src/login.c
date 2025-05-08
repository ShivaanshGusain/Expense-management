#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool login(){
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if(strcmp(username, "admin") == 0 && strcmp(password, "password") == 0){
        printf("Login successful!\n");
        return true;
    } else {
        printf("Invalid username or password.\n");
        return false;
    }
}