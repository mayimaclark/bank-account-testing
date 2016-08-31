#include "bank_account.h"
#include <stdio.h>

char* was_success(int value)
{
    char* s = "failed";
    if(value == 1)
        s = "succeeded";
    return s;
}


int main()
{
    //Create valid account
    bank_account* b1 = create_account("Bob",5000,"1");

    //Display valid account
    display_account(b1);

    //Withdraw valid amount
    int test = withdraw(b1,5000);
    char* t = was_success(test);
    printf("Withdraw 5000 %s\n", t);
    display_account(b1);

    //Withdraw invalid amount
    int test2 = withdraw(b1,5000);
    char* t2 = was_success(test2);
    printf("Withdraw 5000 %s\n", t2);
    display_account(b1);

    //Deposit valid amount
    int test3 = deposit(b1,5000);
    char* t3 = was_success(test3);
    printf("Deposit 5000 %s\n", t3);
    display_account(b1);

    //Deposit invalid amount
    int test4 = deposit(b1,-5000);
    char* t4 = was_success(test4);
    printf("Deposit -5000 %s\n", t4);
    display_account(b1);

    //Delete valid account
    delete_account(b1);

    return 0;
}
