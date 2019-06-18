#ifndef __WITH_MUTEX_H_INCLUDED
#define __WITH_MUTEX_H_INCLUDED

#include <mutex>
#include <thread>

#define define_scoped_lock(lock) \
  scoped_lock_t lock(mutex());
#define define_unique_lock(lock) \
  unique_lock_t lock(mutex());

template <class MutexType>
class with_basic_mutex {
  using mutex_t = MutexType;
  mutex_t _mutex;
protected:
  using scoped_lock_t = std::scoped_lock<mutex_t>;
  using unique_lock_t = std::unique_lock<mutex_t>;
  mutex_t &mutex() { return _mutex; }
};

template <class MutexType>
class with_basic_static_mutex {
  using mutex_t = MutexType;
  static mutex_t _mutex;
protected:
  using scoped_lock_t = std::scoped_lock<mutex_t>;
  static mutex_t &mutex() { return _mutex; }
};

template <class MutexType>
MutexType with_basic_static_mutex<MutexType>::_mutex;

using with_mutex = with_basic_mutex<std::mutex>;
using with_static_mutex = with_basic_static_mutex<std::mutex>;

#endif // __WITH_MUTEX_H_INCLUDED
