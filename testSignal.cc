#include "Signal.h"

#include <iostream>

#include <gtest/gtest.h>

TEST(InitTest, init){
  sig::Signal<void(int)> test;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
