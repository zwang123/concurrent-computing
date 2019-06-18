#ifndef __PRODUCER_CONSUMER__SOLUTION_H_INCLUDED
#define __PRODUCER_CONSUMER__SOLUTION_H_INCLUDED
#include <array>
#include <iostream>
//#include <thread>

#include "ProducerConsumer.h"

class Solution {
  using size_type = unsigned;
  ProducerConsumer<size_type, 2> buffer;
  static constexpr std::array<size_type, 1> init {0};
public:
  //Solution() { buffer.push(0); }
  Solution() : buffer(init.cbegin(), init.cend()) {}
  void run() {
    auto res = buffer.pop();
    buffer.push(++res);
    std::cout << res << ' ';
  }
  //ProducerConsumer<std::thread::id, 2> buffer;
  //void run() {
  //  buffer.push(std::this_thread::get_id());
  //  std::cout << buffer.pop() << ' ';
  //}
};

#endif // __PRODUCER_CONSUMER__SOLUTION_H_INCLUDED
