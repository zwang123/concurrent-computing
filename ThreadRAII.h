#ifndef __THREAD_RAII_H_INCLUDED
#define __THREAD_RAII_H_INCLUDED

#include <thread>
#include <utility>
struct ThreadRAII {
  std::thread thread;

  template <class ...Args>
  explicit ThreadRAII(Args&&... args) : thread(std::forward<Args>(args)...) {}
  ThreadRAII(const ThreadRAII&) = delete;
  ThreadRAII(ThreadRAII&& other) : thread(std::move(other.thread)) {}

  ~ThreadRAII() {if (thread.joinable()) thread.join();}
};

#endif // __THREAD_RAII_H_INCLUDED
