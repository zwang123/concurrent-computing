#ifndef __AVOID_BUSY_WAITING__SOLUTION_H_INCLUDED
#define __AVOID_BUSY_WAITING__SOLUTION_H_INCLUDED

#include <functional>
#include <future>
#include <thread>
#include "../ThreadRAII.h"

struct Solution {

  static void task() {
  }

  static void set_promise(std::promise<int> &promiseObj) {
    task();
    promiseObj.set_value(0);
  }

  static void run() {
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    ThreadRAII th(set_promise, std::ref(promiseObj));
    futureObj.get();
  }

};

#endif // __AVOID_BUSY_WAITING__SOLUTION_H_INCLUDED
