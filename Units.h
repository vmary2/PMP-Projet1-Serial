#ifndef UNITS_H
#define UNITS_H

#include <cstdint>
#include <iostream>
#include <ratio>


namespace phy {

  /*
   * A unit defined in terms of the base units
   */
  template<int Metre, int Kilogram, int Second, int Ampere, int Kelvin, int Mole, int Candela>
  struct Unit {
    static constexpr int metre = Metre;
    static constexpr int kilogram = Kilogram;
    static constexpr int second = Second;
    static constexpr int ampere = Ampere;
    static constexpr int kelvin = Kelvin;
    static constexpr int mole = Mole;
    static constexpr int candela = Candela;
  };


 namespace details {

    template<class U1, class U2>
    using Unit_multiply = Unit<U1::metre + U2::metre, U1::kilogram + U2::kilogram, U1::second + U2::second, U1::ampere + U2::ampere, U1::kelvin + U2::kelvin, U1::mole + U2::mole, U1::candela + U2::candela>;


    template<class U1, class U2>
    using Unit_divide = Unit<U1::metre - U2::metre, U1::kilogram - U2::kilogram, U1::second - U2::second, U1::ampere - U2::ampere, U1::kelvin - U2::kelvin, U1::mole - U2::mole, U1::candela - U2::candela>;

  }

  /*
   * Various type aliases
   */

  using Metre     = Unit<1,0,0,0,0,0,0>;
  using Kilogram  = Unit<0,1,0,0,0,0,0>;
  using Second    = Unit<0,0,1,0,0,0,0>;
  using Ampere    = Unit<0,0,0,1,0,0,0>;
  using Kelvin    = Unit<0,0,0,0,1,0,0>;
  using Mole      = Unit<0,0,0,0,0,1,0>;
  using Candela   = Unit<0,0,0,0,0,0,1>;
  using Radian    = Unit<0,0,0,0,0,0,0>; // metre \ metre


  /*
   * A quantity is a value associated with a unit and a ratio
   */
  template<class U, class R = std::ratio<1>>
  struct Qty {
    using Unit = U;
    using Ratio = R;

    intmax_t value;

    Qty(){
      value = 0;
    }

    Qty(intmax_t v){
      value = v;
    }

    template<typename ROther>
    Qty& operator+=(Qty<U, ROther> other){
      using Ratio = std::ratio_divide<ROther, R>;
      this->value = this->value + other.value * Ratio::num / Ratio::den;
      return *this;
    }

    template<typename ROther>
    Qty& operator-=(Qty<U, ROther> other){
      using Ratio = std::ratio_divide<ROther, R>;
      this->value = this->value - other.value * Ratio::num / Ratio::den;
      return *this;
    }

  };


  /*
   * Various quantities
   */

  using Length = Qty<Metre>;
  using Mass =Qty<Kilogram>;
  using Time = Qty<Second>;
  using Current = Qty<Ampere>;
  using Temperature = Qty<Kelvin>;
  using Amount = Qty<Mole>;
  using LuminousIntensity = Qty<Candela>;

  /*
   * Some weird quantities
   */

  using Mile = Qty<Metre, std::ratio<1609>>;
  using Yard = Qty<Metre, std::ratio<1000000, 1093613>>;
  using Foot = Qty<Metre, std::ratio<1000000, 3280840>>;
  using Inch = Qty<Metre, std::ratio<1000000, 39370079>>;

  /*
   * Comparison operators
   */

  template<typename U, typename R1, typename R2>
  bool operator==(Qty<U, R1> q1, Qty<U, R2> q2){
    return q1.value * R1::num / R1::den == q2.value * R2::num /R2::den;
  }

  template<typename U, typename R1, typename R2>
  bool operator!=(Qty<U, R1> q1, Qty<U, R2> q2){
    return q1.value * R1::num / R1::den != q2.value * R2::num /R2::den; 
  }

  template<typename U, typename R1, typename R2>
  bool operator<(Qty<U, R1> q1, Qty<U, R2> q2){
    return q1.value * R1::num / R1::den < q2.value * R2::num /R2::den; 
  }

  template<typename U, typename R1, typename R2>
  bool operator<=(Qty<U, R1> q1, Qty<U, R2> q2){
    return q1.value * R1::num / R1::den <= q2.value * R2::num /R2::den; 
  }

  template<typename U, typename R1, typename R2>
  bool operator>(Qty<U, R1> q1, Qty<U, R2> q2){
    return q1.value * R1::num / R1::den > q2.value * R2::num /R2::den; 
  }

  template<typename U, typename R1, typename R2>
  bool operator>=(Qty<U, R1> q1, Qty<U, R2> q2){
    return q1.value * R1::num / R1::den >= q2.value * R2::num /R2::den; 
  }

  /*
   * Arithmetic operators
   */

  template<typename U, typename R1, typename R2>
  Qty<U, typename std::conditional<std::ratio_less_equal<R1, R2>::value, R1, R2>::type> operator+(Qty<U, R1> q1, Qty<U, R2> q2){
    using TargetRatio = typename std::conditional<std::ratio_less_equal<R1, R2>::value, R1, R2>::type;
    using ConvertionRatio = std::ratio_divide<R1, R2>;
    if(std::is_same<TargetRatio, R1>()){ // R1 -> target
      return Qty<U, TargetRatio>( q1.value + q2.value * ConvertionRatio::den / ConvertionRatio::num);
    }
    // R2 -> target
    return Qty<U, TargetRatio>( q1.value * ConvertionRatio::num / ConvertionRatio::den + q2.value);
  }

  template<typename U, typename R1, typename R2>
  Qty<U, typename std::conditional<std::ratio_less_equal<R1, R2>::value, R1, R2>::type> operator-(Qty<U, R1> q1, Qty<U, R2> q2){
    using TargetRatio = typename std::conditional<std::ratio_less_equal<R1, R2>::value, R1, R2>::type;
    using ConvertionRatio = std::ratio_divide<R1, R2>;
    if(std::is_same<TargetRatio, R1>()){ // R1 -> target
      return Qty<U, TargetRatio>( q1.value - q2.value * ConvertionRatio::den / ConvertionRatio::num);
    }
    // R2 -> target
    return Qty<U, TargetRatio>( q1.value * ConvertionRatio::num / ConvertionRatio::den - q2.value);
  }

  template<typename U1, typename R1, typename U2, typename R2>
  Qty<details::Unit_multiply<U1, U2>, std::ratio_multiply<R1, R2>> operator*(Qty<U1, R1> q1, Qty<U2, R2> q2){
    using TargetRatio = std::ratio_multiply<R1, R2>;
    using TargetUnit = details::Unit_multiply<U1, U2>;
    return Qty<TargetUnit, TargetRatio>(q1.value * R2::num / R2::den * q2.value * R1::num / R1::den);
  }

  template<typename U1, typename R1, typename U2, typename R2>
  Qty<details::Unit_divide<U1, U2>, std::ratio_divide<R1, R2>> operator/(Qty<U1, R1> q1, Qty<U2, R2> q2){
    using TargetRatio = std::ratio_divide<R1, R2>;
    using TargetUnit = details::Unit_divide<U1, U2>;
    return Qty<TargetUnit, TargetRatio>((q1.value * (R1::num / R1::den)) / (q2.value * (R2::num / R2::den)));
  }


  /*
   * Cast function between two quantities
   */
  template<typename ResQty, typename U, typename R>
  ResQty qtyCast(Qty<U,R> q){
    static_assert(std::is_same<typename ResQty::Unit, U>::value); // L'arrivée n'a pas la même unité que le départ
    ResQty ret;
    ret += q;
    return ret;
  }

  namespace literals {

    /*
     * Some user-defined literals
     */

    Length operator "" _metres(unsigned long long int val){
      Qty<Metre> ret(val);
      return ret; 
    }
    Mass operator "" _kilograms(unsigned long long int val){
      Qty<Kilogram> ret(val);
      return ret; 
    }
    Time operator "" _seconds(unsigned long long int val){
      Qty<Second> ret(val);
      return ret; 
    }
    Current operator "" _amperes(unsigned long long int val){
      Qty<Ampere> ret(val);
      return ret; 
    }
    Temperature operator "" _kelvins(unsigned long long int val){
      Qty<Kelvin> ret(val);
      return ret; 
    }
    Amount operator "" _moles(unsigned long long int val){
      Qty<Mole> ret(val);
      return ret; 
    }
    LuminousIntensity operator "" _candelas(unsigned long long int val){
      Qty<Candela> ret(val);
      return ret; 
    }

  }

}

#endif // UNITS_H
