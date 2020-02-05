#include "Signal.h"

#include <iostream>

#include <gtest/gtest.h>

namespace sigtest
{
  struct NonCopyable{
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator = (const NonCopyable&) = delete;
    NonCopyable(NonCopyable&&) = default;
    NonCopyable& operator = (NonCopyable&&) = default;
  };

  struct NonMovable{
    NonMovable() = default;
    NonMovable(const NonMovable&) = default;
    NonMovable& operator = (const NonMovable&) = default;
    NonMovable(NonMovable&&) = delete;
    NonMovable& operator = (NonMovable&&) = delete;
  };

  struct NonMovableAndCopyable{
    NonMovableAndCopyable() = default;
    NonMovableAndCopyable(const NonMovableAndCopyable&) = delete;
    NonMovableAndCopyable& operator = (const NonMovableAndCopyable&) = delete;
    NonMovableAndCopyable(NonMovableAndCopyable&&) = delete;
    NonMovableAndCopyable& operator = (NonMovableAndCopyable&&) = delete;
  };

} // namespace sigtest


void callback ( int param ) {
 std::cout << "Here is your Integer : " << param << std::endl;
}

TEST(VoidReturnTest, TeacherTestDiscard){
  sig::Signal<void(int)> sig ;
  // connect a simple function
  sig.connectSlot ( callback );
  // connect a lambda function
  int res = 0;
  sig.connectSlot ([& res ]( int x ) { res = x ; });
  // emit the signal
  sig.emitSignal(1);

  ASSERT_EQ(1, res);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
