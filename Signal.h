#ifndef SIGNAL_H
#define SIGNAL_H

#include <type_traits>
#include <iostream>
#include <vector>
#include <functional>
#include <map>

namespace sig {

  /*
   * Combiner that discards all values
   */
  class DiscardCombiner {
  public:
    using result_type = void;

    template<typename U>
    void combine(const U&) {
        return;
    }

    result_type result() {
        return;
    }
  };

  /*
   * Combiner that keeps only the last value
   */
  template<typename T>
  class LastCombiner {
  public:
    using result_type = T;

    result_type res;

    template<typename U>
    void combine(const U& item) {
      res = item;
    }

    result_type result() {
      return res;
    }
  };

  /*
   * Combiner that keeps all values in a vector
   */
  template<typename T>
  class VectorCombiner {
  public:
    using result_type = std::vector<T>;

    result_type res;

    template<typename U>
    void combine(const U& item) {
      res.push_back(item);
    }

    result_type result() {
      return res;
    }
  };

  /*
   * A signal
   */
  template< class,class U = DiscardCombiner> 
  class Signal;

  template<typename R, typename Combiner, typename ...Args>
  class Signal<R(Args...), Combiner> {
  private:
    std::size_t id = 0;
  public:
  
    // result of combiner
    using result_type = typename Combiner::result_type;

    // callbacks
    std::map<std::size_t,std::function<R(Args...)>> funcs;
   
    // Combiner : default = DiscardCombiner
   
    Combiner c;
    // constructor
    Signal(Combiner combiner = Combiner()) : funcs() {
        c = std::move(combiner);
    }


    // connect the function to the signal and returns an id
    template<typename Func>
    std::size_t connectSlot(Func callback) {
        std::function<R(Args...)> newfunc = callback;
        funcs.insert({id, callback});
        return id++;
    }

    // disconnect the function represented by the id
    void disconnectSlot(std::size_t id) {
        funcs.erase(id);
    }

    // emit a signal, call all the slots
    result_type emitSignal(Args... args) {
      for(auto &fun : funcs){
        c.combine(fun.second(args...));
      }
      return c.result();
    }
  };


  // Template spec for void function
  template<typename Combiner, typename ...Args>
  class Signal<void(Args...), Combiner> {
  private:
    std::size_t id = 0;
  public:
  
    // callbacks
    std::map<std::size_t,std::function<void(Args...)>> funcs;
   
    // Combiner : default = DiscardCombiner
   
    Combiner c;
    // constructor
    Signal(Combiner combiner = Combiner()) : funcs() {
        c = std::move(combiner);
    }


    // connect the function to the signal and returns an id
    template<typename Func>
    std::size_t connectSlot(Func callback) {
        std::function<void(Args...)> newfunc = callback;
        funcs.insert({id, callback});
        return id++;
    }

    // disconnect the function represented by the id
    void disconnectSlot(std::size_t id) {
        funcs.erase(id);
    }

    // emit a signal, call all the slots
    void emitSignal(Args... args) {
      for(auto &fun : funcs){
        fun.second(args...);
      }
    }
  };


}
#endif // SIGNAL_H
