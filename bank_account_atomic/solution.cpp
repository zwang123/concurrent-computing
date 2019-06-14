#include <iostream>
#include "account.h"
#include "solution.h"
#include "../RandomNumberGenerator.h"
#include "../TimeSeed.h"

Solution::Solution(double init, double min, double max) 
  : account(init), rng_int(0, 1), rng_dbl(min, max)
{
  //rng_int.seed(0);
  //rng_dbl.seed(0);
  //rng_int.seed(TimeSeed::gen_seed());
  //rng_dbl.seed(TimeSeed::gen_seed());
}

Solution::~Solution()
{
  std::cout << account.balance() << std::endl;
}

//void Solution::run()
//{
//  const auto tmp = gen_random();
//  if (tmp.first)
//    account.deposit(tmp.second);
//  //else
//  //  account.withdraw(tmp.second);
//  //define_scoped_lock(lock);
//  //std::cout << tmp.first << ' ' << tmp.second << ' '
//  //          << account.balance() << std::endl;
//}

void Solution::run()
{
  account.deposit(1.);
}

std::pair<int, double> Solution::gen_random()
{
  define_scoped_lock(lock);
  return {rng_int(), rng_dbl()};
}

