#include "bank.h"
#include <stdbool.h>
#include <assert.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// see bank.h for details

static int balance = 0;

void deposit(int amount) {
  balance += amount;
}

// DO NOT MODIFY THE ABOVE TWO DEFINITIONS
// COMPLETE THE IMPLEMENTATION BELOW:

//BANK CONSTANTS:

static int daily_withdraw_limit = 100000;

static int limit_increase_amount = 10000;

static int overdraft_penalty = 500;

const int original_withdraw_limit = 100000;

//MONEY CONVERSION CONSTANTS:

static int cents_per_dollar = 100;

//BONUS QUESTION CONSTANTS:

//keeps track of if account has been withdrawn from today
static int withdrew = 0;

//keeps track of how many days the balance has been above $500
static int days_above_500 = 1;

//keeps track of when the last limit increase was
//starts at 11 since the user is able to immediately increase
//limit
static int days_since_last_increase = 11;

//keeps track of if the balance has ever been <-1000
static int under_neg_1000 = 0;

//keeps track of how many times the limit has been increased
static int limit_increase_num = 0;

//if the account is ever 1000 under, there will be no limit 
//increase
static int never_increase_limit_cutoff = -100000;

//cutoff for if days over $500 counter will be increased
static int bal_over_500_cutoff = 50000;

//cutoff for bal over $1000
static int bal_over_1000 = 100000;

//days over $500 cutoff
static int five_days_over_500_cutoff = 5;

//days since last increase cutoff
static int days_since_increase_cutoff = 10;

//===========================================================

//BANK FUNCTIONS:

//see .h for descriptions

void withdrawal(int amount){
  assert(amount>0);
  withdrew = 1;
  if(amount<=daily_withdraw_limit){
    balance -= amount;
    daily_withdraw_limit -= amount;
  }
  else {
    printf("no withdrawal: daily limit exceeded\n"); 
  }
  if(balance<never_increase_limit_cutoff) {
    under_neg_1000 = 1;
  }
}

void print_balance(void){
  if(balance>=0) {
    const int cents = balance%cents_per_dollar;
    const int dollars = balance/cents_per_dollar;
    printf("balance: $%d.%02d\n", dollars, cents);
  }
  else {
    const int cents = balance%cents_per_dollar;
    const int dollars = (balance/cents_per_dollar)*-1;
    printf("balance: -$%d.%02d\n", dollars, cents);
  }
}

void print_limit(void){
  assert(daily_withdraw_limit>=0);
  const int cents = daily_withdraw_limit%cents_per_dollar;
  const int dollars = daily_withdraw_limit/cents_per_dollar;
  printf("limit: $%d.%02d\n", dollars, cents);
}

void new_day(void){
  withdrew = 0;
  days_since_last_increase += 1;
  if(balance>=bal_over_500_cutoff) {
    days_above_500 += 1;
  }
  else {
    days_above_500 = 0;
  }
  if(balance>=0){
    daily_withdraw_limit = original_withdraw_limit 
      + limit_increase_amount*limit_increase_num;
  }
  else {
    daily_withdraw_limit = 0;
    balance -= overdraft_penalty;
    printf("Warning! Overdraft\n");
  }
}

// KEEP THIS DEFINIITON IF YOU CHOOSE NOT TO DO THE BONUS
//see .h for description
//see BONUS QUESTION CONSTANTS section for constant amounts
void request_limit_increase(void) {
  if((balance>=bal_over_1000) && (!withdrew) 
     && (days_above_500>=five_days_over_500_cutoff)
     && (days_since_last_increase>=days_since_increase_cutoff) 
     && (!under_neg_1000)){
    days_since_last_increase = 0;
    limit_increase_num +=1;
  }
}
