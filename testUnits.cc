#include "Units.h"

#include <iostream>

#include <gtest/gtest.h>

using namespace phy::literals;

TEST(TestUnits, VelocityTest){
    auto velocity = 100000_metres / 3600_seconds;
    EXPECT_TRUE(velocity.value == 27);

    //Type verification of velocity
    phy::Qty<phy::Unit<1,0,-1,0,0,0,0>, std::ratio<1>> velocity2(33);
    EXPECT_NO_THROW(velocity + velocity2);
}

TEST(TestUnits, AdditionTestMeterDifferentRatio){
    phy::Qty<phy::Metre, std::ratio<1,6>> lhs(3);
    phy::Qty<phy::Metre, std::ratio<2,3>> rhs(5);
    auto ResAdd = lhs + rhs;
    lhs += rhs;
    EXPECT_EQ(ResAdd.value, 23);
    EXPECT_EQ(lhs.value, 23);
}

TEST(TestUnits, AdditionTestMileMeter){
    phy::Qty<phy::Metre, std::ratio<1,1>> lhs(3);
    phy::Mile rhs(5);
    auto ResAdd = lhs + rhs;
    lhs += rhs;
    EXPECT_EQ(ResAdd.value, 8048);  
    EXPECT_EQ(lhs.value, 8048);
}

TEST(TestUnits, AdditionTestMeterSameRatio){
    phy::Qty<phy::Metre, std::ratio<1>> lhs(3);
    phy::Qty<phy::Metre, std::ratio<1>> rhs(5);
    auto ResAdd = lhs + rhs;
    lhs += rhs;
    EXPECT_EQ(ResAdd.value, 8);  
    EXPECT_EQ(lhs.value, 8);
}

TEST(TestUnits, SoustractionTestMeterSameRatio){
    phy::Qty<phy::Metre, std::ratio<1>> lhs(5);
    phy::Qty<phy::Metre, std::ratio<1>> rhs(3);
    auto ResSub = lhs - rhs;
    lhs -= rhs;
    EXPECT_EQ(ResSub.value, 2);
    EXPECT_EQ(lhs.value, 2);
}

TEST(TestUnits, SoustractionTestMeterDifferentRatio){
    phy::Qty<phy::Metre, std::ratio<1,6>> lhs(3);
    phy::Qty<phy::Metre, std::ratio<2,3>> rhs(5);
    auto ResSub = lhs - rhs;
    lhs -= rhs;
    EXPECT_EQ(ResSub.value, -17);
    EXPECT_EQ(lhs.value, -17);
}

TEST(TestUnits, MultiplicationTestMeterSameRatio){
    phy::Qty<phy::Metre, std::ratio<1,1>> lhs(3);
    phy::Qty<phy::Metre, std::ratio<1,1>> rhs(5);
    auto ResMult = lhs * rhs;
    EXPECT_EQ(ResMult.value, 15);
}

TEST(TestUnits, MultiplicationTestMeterDifferentRatio){
    phy::Qty<phy::Metre, std::ratio<1,2>> lhs(4);
    phy::Qty<phy::Metre, std::ratio<1,1>> rhs(5);
    auto ResMult = lhs * rhs;
    EXPECT_EQ(ResMult.value, 10);
}

TEST(TestUnits, MultiplicationTestMeterDifferentRatio2){
    phy::Qty<phy::Metre, std::ratio<2,1>> lhs(4);
    phy::Qty<phy::Metre, std::ratio<1,1>> rhs(5);
    auto ResMult = lhs * rhs;
    EXPECT_EQ(ResMult.value, 40);
}

TEST(TestUnits, DivisionTestMeterSameRatio){
    phy::Qty<phy::Metre, std::ratio<1,1>> lhs(6);
    phy::Qty<phy::Metre, std::ratio<1,1>> rhs(3);
    auto ResDiv = lhs / rhs;
    EXPECT_EQ(ResDiv.value, 2);
}

TEST(TestUnits, DivisionTestMeterDifferentRatio){
    phy::Qty<phy::Metre, std::ratio<2,1>> lhs(6);
    phy::Qty<phy::Metre, std::ratio<1,1>> rhs(2);
    auto ResDiv = lhs / rhs;
    EXPECT_EQ(ResDiv.value, 6);
}

TEST(TestUnits, DivisionTestMeterDifferentRatio2){
    phy::Qty<phy::Metre, std::ratio<1>> lhs(6);
    phy::Qty<phy::Metre, std::ratio<2>> rhs(3);
    auto ResDiv = lhs / rhs;
    EXPECT_EQ(ResDiv.value, 1);
}

TEST(TestUnits, DivisionTestMeterRhsLower){
    phy::Qty<phy::Metre, std::ratio<1,1>> lhs(4);
    phy::Qty<phy::Metre, std::ratio<1,1>> rhs(8);
    auto ResDiv = lhs / rhs;    //Res is technically 1/2 but it's lowered to 0
    EXPECT_EQ(ResDiv.value, 0);
}

TEST(TestUnits, CastTest){
    phy::Qty<phy::Metre ,std::milli> mm(32);
    auto nm = phy::qtyCast<phy::Qty<phy::Metre, std::nano>>(mm);
    printf("value : %ld\n", nm.value);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
