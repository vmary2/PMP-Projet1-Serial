#include "Units.h"

#include <iostream>

#include <gtest/gtest.h>

using namespace phy::literals;

TEST(TestUnits, AdditionTest){
    phy::Qty<phy::Metre, std::ratio<1>> dist(100000);
    phy::Qty<phy::Second, std::ratio<1>> time(3600);
    auto velocity = dist / time;
    EXPECT_TRUE(velocity.value > 26);
    EXPECT_TRUE(velocity.value < 28);
}

TEST(TestUnits, OperationTests){
    phy::Qty<phy::Metre, std::ratio<1,6>> lhs(3);
    phy::Qty<phy::Metre, std::ratio<2,3>> rhs(5);
    auto ResAdd = lhs + rhs;
    EXPECT_EQ(ResAdd.value, 23);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
