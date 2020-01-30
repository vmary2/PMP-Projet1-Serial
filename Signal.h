#ifndef SIGNAL_H
#define SIGNAL_H

#include <type_traits>
#include <vector>
#include <functional>

namespace sig {

  /*
   * Combiner that discards all values
   */
  class DiscardCombiner {
  public:
    using result_type = /* implementation defined */;

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
    using result_type = /* implementation defined */;

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
    using result_type = /* implementation defined */;

    template<typename U>
    void combine(const U& item) {
    }

    result_type result() {
    }
  };

  /*
   * A signal
   */
  template<typename Signature, typename Combiner = DiscardCombiner>
  class Signal {
  public:
    // result of combiner
    using result_type = /* implementation defined */;

    // constructor
    Signal(Combiner combiner = Combiner()) {

    }

    // connect the function to the signal and returns an id
    template<typename Func>
    std::size_t connectSlot(Func callback) {
    }

    // disconnect the function represented by the id
    void disconnectSlot(std::size_t id) {
    }

    // emit a signal, call all the slots
    result_type emitSignal(/* arguments of the signature */ args) {
    }
  };

}

#endif // SIGNAL_H
