#include "account.h"

bool Account::deposit(double amount)
{
  if (amount < 0.) return false; // cannot deposit negative
  userBalance += amount * mult;
  return true;
}

// compare and store should be atomic TODO
//bool Account::withdraw(double amount)
//{
//  if (amount < 0.) return false; // cannot withdraw negative
//  unsigned amt_mult = amount * mult;
//  unsigned og = userBalance.fetch_sub(amt_mult);
//  if (userBalance > og) return false; // insufficient fund
//  userBalance -= amt_mult;
//  return true;
//}
