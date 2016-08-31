#ifndef _BANK_H
#define _BANK_H

typedef struct bank_account_struct
{
    char* owner;
    char* account_number;
    float balance;
}bank_account;

/***********************************************
precondition: name cannot be NULL and has at least 1 character
precondition: initial_balance is non-negative
precondition: num cannot be NULL and has at least 1 characters, all characters are digits
returns NULL if any precondition is not satisfied
************************************************/
bank_account* create_account (char* name, float initial_balance, char* num);

/***********************************************
precondition: acct cannot be NULL
assertion fails if s is NULL
************************************************/
void display_account(bank_account* acct);

/***********************************************
precondition: acct cannot be NULL
returns whether deposit was successful
assertion fails if s is NULL
************************************************/
int deposit(bank_account* acct, float amount);

/***********************************************
precondition: acct cannot be NULL
returns whether withdraw was successful
assertion fails if s is NULL
************************************************/
int withdraw(bank_account* acct, float amount);

/***********************************************
precondition: acct cannot be NULL
assertion fails if s is NULL
************************************************/
void delete_account(bank_account* acct);

#endif // _BANK_H
