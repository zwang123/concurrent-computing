#include <cstddef>
#include <thread>
#include <vector>

#include "solution.h"

#ifndef DEFAULT_NUM_THREADS
#define DEFAULT_NUM_THREADS 4
#endif

inline static
void set_nthreads(char *s, std::size_t &nthreads)
{
  unsigned long tmp = strtoul(s, nullptr, 0);
  if (tmp > 0) nthreads = tmp;
}

int main(int argc, char **argv)
{
  // nthreads is by default 4 unless overriden by DEFAULT_NUM_THREADS
  std::size_t nthreads = DEFAULT_NUM_THREADS;
  // set nthreads based on argv[1]
  if (argc > 1) set_nthreads(argv[1], nthreads);

  // run the solution of the problem
  Solution sln;
  std::vector<std::thread> threads;
  for (std::size_t i = 0; i != nthreads; ++i)
      threads.emplace_back([&sln](){sln.run();});

  // join the threads
  for (auto &th : threads) {
    th.join();
  }

  // exit the program
  return 0;
}
