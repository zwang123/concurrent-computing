#ifndef __BANK_ACCOUNT_ATOMIC__ACCOUNT_H_INCLUDED
#define __BANK_ACCOUNT_ATOMIC__ACCOUNT_H_INCLUDED
#include <atomic>
#include <cassert>
#include <climits>

class Account {
  static constexpr double mult = 100.;
  static constexpr double div = .01;
  static constexpr double max_amount = INT_MAX * div;
  std::atomic_int userBalance;
public:
  Account(double newBalance = 0.) : userBalance(newBalance*mult) 
  {assert( newBalance >= 0. );}
  bool deposit(double amount);
  bool withdraw(double amount);
  double balance() const { return userBalance.load() * div; }
};
#endif // __BANK_ACCOUNT_ATOMIC__ACCOUNT_H_INCLUDED
