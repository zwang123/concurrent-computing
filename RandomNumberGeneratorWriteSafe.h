#ifndef __RANDOM_NUMBER_GENERATOR_WRITE_SAFE_H_INCLUDED
#define __RANDOM_NUMBER_GENERATOR_WRITE_SAFE_H_INCLUDED

//#include <limits>
#include <random>
#include <utility>

#include "with_mutex.h"

#ifdef __x86_64__
#  define DEFAULT_GENERATOR std::mt19937_64
#else
#  define DEFAULT_GENERATOR std::mt19937
#endif

// Default distribution: uniform in [0.0, 1.0)
// Default type: double
template <typename _Distribution = std::uniform_real_distribution<>,
          typename _Generator = DEFAULT_GENERATOR>
class RandomNumberGenerator final : public with_static_mutex {
public:
  using result_type = typename _Distribution::result_type;
  using param_type = typename _Distribution::param_type;
  using seed_type = typename _Generator::result_type;

  // Constructor
  template <typename ...Args>
  explicit RandomNumberGenerator(Args&&... args)
    : dis(std::forward<Args>(args)...)
  {}

  // Random number generator
  result_type operator() () {define_scoped_lock(lock); return dis(gen);}
  result_type operator() (const param_type &parm) 
  {define_scoped_lock(lock); return dis(gen, parm);}
  
  // Reset
  void reset() {define_scoped_lock(lock); dis.reset();}

  // Parameters
  param_type param() const {return dis.param();}
  void param(const param_type &parm) 
  {define_scoped_lock(lock); dis.param(parm);}

  // Min Max
  result_type min() const {return dis.min();}
  result_type max() const {return dis.max();}

  // set seed
  template <typename ...Args>
  static void seed (Args&&... args) 
  {define_scoped_lock(lock); gen.seed(std::forward<Args>(args)...);}

private:
  static _Generator gen;
  _Distribution dis;
};

template <typename _Distribution, typename _Generator>
_Generator RandomNumberGenerator<_Distribution, _Generator>::gen;

#endif // __RANDOM_NUMBER_GENERATOR_WRITE_SAFE_H_INCLUDED
