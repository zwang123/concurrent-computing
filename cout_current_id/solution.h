#ifndef __COUT_CURRENT_ID__SOLUTION_H_INCLUDED
#define __COUT_CURRENT_ID__SOLUTION_H_INCLUDED

#include <iostream>
#include <thread>

#include "../with_mutex.h"

class Solution : public with_mutex {
public:
  void run() {
    define_scoped_lock(lock);
    std::cout << std::this_thread::get_id() << std::endl;
  }
};

#endif // __COUT_CURRENT_ID__SOLUTION_H_INCLUDED
