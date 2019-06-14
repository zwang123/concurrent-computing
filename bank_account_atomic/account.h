#ifndef __BANK_ACCOUNT_ATOMIC__ACCOUNT_H_INCLUDED
#define __BANK_ACCOUNT_ATOMIC__ACCOUNT_H_INCLUDED
#include <atomic>
#include <cassert>

class Account {
  static constexpr double mult = 100.;
  static constexpr double div = .01;
  std::atomic_uint userBalance;
public:
  Account(double newBalance = 0.) : userBalance(newBalance*mult) 
  {assert( newBalance >= 0. );}
  bool deposit(double amount);
  bool withdraw(double amount);
  double balance() const { return userBalance.load() * div; }
};
#endif // __BANK_ACCOUNT_ATOMIC__ACCOUNT_H_INCLUDED
