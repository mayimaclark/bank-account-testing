#include "bank_account.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

int all_digits(char* s)
{
    assert(s != NULL);
    int i = 0;
    while(i < strlen(s) && isdigit(s[i]))
        i++;
    return i == strlen(s);
}

int is_valid_name(char* name)
{
    return name != NULL && strlen(name) > 0;
}

int is_valid_initial_balance(float initial_balance)
{
    return initial_balance >= 0;
}

int is_valid_num(char* num)
{
    return num != NULL && all_digits(num);
}

bank_account* create_account(char* name, float initial_balance, char* num)
{
    bank_account* acct = NULL;
    if(is_valid_name(name) && is_valid_initial_balance(initial_balance) && is_valid_num(num))
    {
        acct = malloc(sizeof(bank_account));
        acct -> owner = malloc(strlen(name) * sizeof(char));
        strcpy(acct -> owner, name);
        acct -> account_number = malloc(strlen(num) * sizeof(char));
        strcpy(acct -> account_number, num);
        acct -> balance = initial_balance;
    }
    return acct;
}

void display_account(bank_account* acct)
{
    assert(acct != NULL);
    printf("Owner: %s\tAccount Number: %s\tBalance: %f\n", acct -> owner, acct -> account_number, acct -> balance);
}

int deposit(bank_account* acct, float amount)
{
    assert(acct != NULL);
    int i = 0;
    if(amount >= 0)
    {
        i = 1;
        acct -> balance += amount;
    }
    return i;
}

int withdraw(bank_account* acct, float amount)
{
    assert(acct != NULL);
    int i = 0;
    if(amount >= 0 && acct -> balance >= amount)
    {
        i = 1;
        acct -> balance -= amount;
    }
    return i;
}

void delete_account(bank_account* acct)
{
    assert(acct != NULL);
    if(acct -> owner != NULL)
        free(acct -> owner);
    if(acct -> account_number != NULL)
        free(acct -> account_number);
    free(acct);
}
