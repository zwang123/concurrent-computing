#ifndef __BANK_ACCOUNT__ACCOUNT_H_INCLUDED
#define __BANK_ACCOUNT__ACCOUNT_H_INCLUDED
#include "../with_mutex.h"

class Account : public with_mutex {
  double userBalance;
public:
  Account(double newBalance = 0.) : userBalance(newBalance) {}
  bool deposit(double amount);
  bool withdraw(double amount);
  double balance() const { return userBalance; }
};
#endif // __BANK_ACCOUNT__ACCOUNT_H_INCLUDED
