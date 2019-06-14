#ifndef __BANK_ACCOUNT__SOLUTION_H_INCLUDED
#define __BANK_ACCOUNT__SOLUTION_H_INCLUDED
#include <utility>
#include "account.h"
#include "../RandomNumberGenerator.h"
#include "../with_mutex.h"

class Solution : public with_mutex {
  Account account;
  RandomNumberGenerator<std::uniform_int_distribution<>> rng_int;
  RandomNumberGenerator<> rng_dbl;
  std::pair<int, double> gen_random();
public:
  Solution(double init = 0., double min = -1., double max = 10.);
  ~Solution();
  void run();
};
#endif // __BANK_ACCOUNT__SOLUTION_H_INCLUDED
