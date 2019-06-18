#ifndef __PRODUCER_CONSUMER__PRODUCER_CONSUMER_H_INCLUDED
#define __PRODUCER_CONSUMER__PRODUCER_CONSUMER_H_INCLUDED

#include <array>
#include <condition_variable>
#include <cstddef>
#include <stdexcept>
#include <utility>

#include "../with_mutex.h"

template <class T, std::size_t N>
class ProducerConsumer : public with_mutex {
public:
  using value_type = T;
  using size_type = std::size_t;
  static constexpr size_type capacity() noexcept { return N; }
  using buffer_type = std::array<value_type, capacity()>;

  ProducerConsumer() : _front(0), _back(0) {}

  template <class InputIt>
  ProducerConsumer(InputIt first, InputIt last) : _front(0), _back(0) {
    if (static_cast<size_type>(last - first) > capacity())
      throw std::out_of_range("Out of buffer capacity in initialization");
    while (first != last)
      _buffer[_back++] = *first++;
    size() = _back;
    if (_back == capacity()) _back = 0;
  }

  size_type size() const noexcept { return _size; }

  template <class Arg>
  void push(Arg&& elem) {
    {
      define_unique_lock(lock);
      _buffer_full.wait(lock, [this](){return size() != capacity();});
      _buffer[_back++] = std::forward<Arg>(elem);
      _back %= capacity();
      ++size();
    }
    //mutex().unlock();
    _buffer_empty.notify_one();
  }

  value_type pop() {
    value_type res;
    {
      define_unique_lock(lock);
      _buffer_empty.wait(lock, [this](){return size() != 0;});
      res = std::move(_buffer[_front++]);
      _front %= capacity();
      --size();
    }
    //mutex().unlock();
    _buffer_full.notify_one();
    return std::move(res);
  }

private:
  //buffer_type &buffer() { define_scoped_lock(lock); return _buffer; }
  //const buffer_type &buffer() const noexcept { return _buffer; }
  size_type &size() noexcept { return _size; }

  size_type _front;
  size_type _back;
  size_type _size;

  buffer_type _buffer;

  std::condition_variable _buffer_full;
  std::condition_variable _buffer_empty;
};

#endif // __PRODUCER_CONSUMER__PRODUCER_CONSUMER_H_INCLUDED
