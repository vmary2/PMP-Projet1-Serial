#ifndef SIGNAL_H
#define SIGNAL_H

#include <type_traits>
#include <vector>
#include <functional>
#include <unordered_map>

namespace sig {

  /*
   * Combiner that discards all values
   */
  class DiscardCombiner {
  public:
    using result_type = void;

    template<typename U>
    void combine(const U&) {
    }

    result_type result() {
    }
  };

  /*
   * Combiner that keeps only the last value
   */
  template<typename T>
  class LastCombiner {
  public:
    using result_type = T;

    template<typename U>
    void combine(const U& item) {
    }

    result_type result() {
    }
  };

  /*
   * Combiner that keeps all values in a vector
   */
  template<typename T>
  class VectorCombiner {
  public:
    using result_type = std::vector<T>;

    template<typename U>
    void combine(const U& item) {
    }

    result_type result() {
    }
  };

  /*
   * A signal
   */
  template< class,class > 
  class Signal; /* undefined */

  template<typename R, typename Combiner, typename ...Args>
  class Signal<R(Args...), Combiner> {
  public:
  
    // result of combiner
    using result_type = R;
    std::unordered_map<std::size_t,std::function<R(Args...)>> funcs;
    Combiner c;
    // constructor
    Signal(Combiner combiner = Combiner()) {
        c = combiner;
    }


    // connect the function to the signal and returns an id
    template<typename Func>
    std::size_t connectSlot(Func callback) {
        std::function<R(Args...)> newfunc = callback;
        std::size_t id = funcs.size();
        while(funcs.find(id) == funcs.end()){
            id++;
        }
        funcs.insert(id, callback);
        return id;
    }

    // disconnect the function represented by the id
    void disconnectSlot(std::size_t id) {
        funcs.erase(id);
    }

    // emit a signal, call all the slots
    result_type emitSignal(Args... args) {
    }
  };

  

}
#endif // SIGNAL_H
