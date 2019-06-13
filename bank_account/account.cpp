#include "account.h"

bool Account::deposit(double amount)
{
  if (amount < 0.) return false; // cannot deposit negative
  define_scoped_lock(lock);
  userBalance += amount;
  return true;
}

bool Account::withdraw(double amount)
{
  if (amount < 0.) return false; // cannot withdraw negative
  define_scoped_lock(lock);
  if (userBalance < amount) return false; // insufficient fund
  userBalance -= amount;
  return true;
}
