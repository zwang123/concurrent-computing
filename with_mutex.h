#ifndef __WITH_MUTEX_H_INCLUDED
#define __WITH_MUTEX_H_INCLUDED

#include <mutex>
#include <thread>

#define define_scoped_lock(lock) \
  scoped_lock_t lock(mutex());

template <class MutexType>
class with_basic_mutex {
  using mutex_t = MutexType;
  mutex_t _mutex;
protected:
  using scoped_lock_t = std::scoped_lock<mutex_t>;
  mutex_t &mutex() { return _mutex; }
};

using with_mutex = with_basic_mutex<std::mutex>;

#endif // __WITH_MUTEX_H_INCLUDED