#include "account.h"

// TODO is not atomic between += and -=
bool Account::deposit(double amount)
{
  // cannot deposit negative or overflow
  if (amount < 0. || amount > max_amount) return false;
  int amt_mult = amount * mult;
  if ((userBalance += amt_mult) < 0) {
    // overflow
    userBalance -= amt_mult;
    return false;
  }
  return true;
}

bool Account::withdraw(double amount)
{
  // cannot withdraw negative or overflow
  if (amount < 0. || amount > max_amount) return false;

  int amt_mult = amount * mult;
  if ((userBalance -= amt_mult) < 0) {
    // insufficient fund
    userBalance += amt_mult;
    return false;
  }
  return true;
}
