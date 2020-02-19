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

TEST(TestUnits, AdditionTestDifferenceBetweenOperators){
    phy::Qty<phy::Metre, std::ratio<1>> lhs(3);
    phy::Qty<phy::Metre, std::milli> rhs(3);
    auto ResAdd = lhs + rhs;
    lhs += rhs;
    EXPECT_EQ(ResAdd.value, 3003);  
    EXPECT_EQ(lhs.value, 3);
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

TEST(TestUnits, SoustractionTestDifferenceBetweenOperators){
    phy::Qty<phy::Metre, std::ratio<1>> lhs(3);
    phy::Qty<phy::Metre, std::milli> rhs(3);
    auto ResAdd = lhs - rhs;
    lhs -= rhs;
    EXPECT_EQ(ResAdd.value, 2997);  
    EXPECT_EQ(lhs.value, 3);
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
    EXPECT_EQ(nm.value, 32000000);
}

TEST(TestUnits, CastWeirdQuanties){
    phy::Qty<phy::Metre> m(25);
    auto inch = phy::qtyCast<phy::Inch>(m);
    EXPECT_EQ(inch.value, 984);
    auto yard = phy::qtyCast<phy::Yard>(m);
    EXPECT_EQ(yard.value, 27);
    auto foot = phy::qtyCast<phy::Foot>(m);
    EXPECT_EQ(foot.value, 82);
    phy::Qty<phy::Metre, std::kilo> km(10);
    auto mile = phy::qtyCast<phy::Mile>(km);
    EXPECT_EQ(mile.value, 6);
}

TEST(TestUnits, AdditionWeirdQuantitiesAndMeters){
    auto m = phy::Qty<phy::Metre>(30);
    auto inch = phy::Inch(100);
    auto resInchM = inch + m;
    EXPECT_EQ(resInchM.value, 1281); //Result is in inches because inches are smaller than Metre
    auto yard = phy::Yard(100);
    auto resYardM = yard + m;
    EXPECT_EQ(resYardM.value, 132);  //Result is in yards because yards are smaller than Metre
    auto foot = phy::Foot(100);
    auto resFootM = foot + m;
    EXPECT_EQ(resFootM.value, 198);  //Result is in feet because feet are smaller than Metre
    auto km = phy::Qty<phy::Metre, std::kilo>(30);
    auto mile = phy::Mile(100);
    auto resMileKm = mile + km;
    EXPECT_EQ(resMileKm.value, 190); //Result is in kilometre because kilometres are smaller than Miles
}

TEST(TestUnits, SoustractionWeirdQuantitiesAndMeters){
    auto m = phy::Qty<phy::Metre>(30);
    auto inch = phy::Inch(100);
    auto resInchM = m - inch;
    EXPECT_EQ(resInchM.value, 1081); //Result is in inches because inches are smaller than Metre
    auto yard = phy::Yard(100);
    auto resYardM = yard - m;
    EXPECT_EQ(resYardM.value, 68);  //Result is in yards because yards are smaller than Metre
    auto foot = phy::Foot(100);
    auto resFootM = foot - m;
    EXPECT_EQ(resFootM.value, 2);  //Result is in feet because feet are smaller than Metre
    auto km = phy::Qty<phy::Metre, std::kilo>(30);
    auto mile = phy::Mile(100);
    auto resMileKm = mile - km;
    EXPECT_EQ(resMileKm.value, 130); //Result is in kilometre because kilometres are smaller than Miles
}

TEST(TestUnits, MultiplicationWeirdQuantitiesAndMeters){
    auto m = phy::Qty<phy::Metre>(30);
    auto inch = phy::Inch(100);
    auto resInchM = inch * m;
    EXPECT_EQ(resInchM.value, 76);   //Result is in square meters
    auto yard = phy::Yard(100);
    auto resYardM = yard * m;
    EXPECT_EQ(resYardM.value, 2743); //Result is in square meters
    auto foot = phy::Foot(100);
    auto resFootM = foot * m;
    EXPECT_EQ(resFootM.value, 914);  //Result is in squares meters
    auto km = phy::Qty<phy::Metre, std::kilo>(30);
    auto mile = phy::Mile(100);
    auto resMileKm = mile * km;
    EXPECT_EQ(resMileKm.value, 4827000000); //Result is in square meter
}

//Not doing divisions using weird quantities because fuck this shit.

TEST(TestUnits, ComparaisonEqual){
    auto q1 = phy::Qty<phy::Metre>(30);
    auto q2 = phy::Qty<phy::Metre>(30);
    EXPECT_TRUE(q1==q2);
    EXPECT_FALSE(q1!=q2);
    auto q3 = phy::Qty<phy::Metre>(50);
    EXPECT_FALSE(q1==q3);
    EXPECT_TRUE(q1!=q3);
}

TEST(TestUnits, ComparaisonEqualDifferentRatio){
    auto q1 = phy::Qty<phy::Metre, std::kilo>(3);
    auto q2 = phy::Qty<phy::Metre>(3000);
    EXPECT_TRUE(q1==q2);
    EXPECT_FALSE(q1!=q2);
    auto q3 = phy::Qty<phy::Metre>(30);
    EXPECT_FALSE(q1==q3);
    EXPECT_TRUE(q1!=q3);
}

TEST(TestUnits, ComparaisonInferior){
    auto q1 = phy::Qty<phy::Metre>(30);
    auto q2 = phy::Qty<phy::Metre>(30);
    EXPECT_FALSE(q1<q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_FALSE(q1<q3);
    EXPECT_TRUE(q3<q1);
}

TEST(TestUnits, ComparaisonInferiorDifferentRatio){
    auto q1 = phy::Qty<phy::Metre,std::kilo>(3);
    auto q2 = phy::Qty<phy::Metre>(3000);
    EXPECT_FALSE(q1<q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_FALSE(q1<q3);
    EXPECT_TRUE(q3<q1);
}

TEST(TestUnits, ComparaisonInferiorOrEqual){
    auto q1 = phy::Qty<phy::Metre>(30);
    auto q2 = phy::Qty<phy::Metre>(30);
    EXPECT_TRUE(q1<=q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_FALSE(q1<=q3);
    EXPECT_TRUE(q3<=q1);
}

TEST(TestUnits, ComparaisonInferiorOrEqualDifferentRatio){
    auto q1 = phy::Qty<phy::Metre,std::kilo>(3);
    auto q2 = phy::Qty<phy::Metre>(3000);
    EXPECT_TRUE(q1<=q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_FALSE(q1<=q3);
    EXPECT_TRUE(q3<=q1);
}

TEST(TestUnits, ComparaisonSuperior){
    auto q1 = phy::Qty<phy::Metre>(30);
    auto q2 = phy::Qty<phy::Metre>(30);
    EXPECT_FALSE(q1>q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_TRUE(q1>q3);
    EXPECT_FALSE(q3>q1);
}

TEST(TestUnits, ComparaisonSuperiorDifferentRatio){
    auto q1 = phy::Qty<phy::Metre,std::kilo>(3);
    auto q2 = phy::Qty<phy::Metre>(3000);
    EXPECT_FALSE(q1>q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_TRUE(q1>q3);
    EXPECT_FALSE(q3>q1);
}

TEST(TestUnits, ComparaisonSuperiorOrEqual){
    auto q1 = phy::Qty<phy::Metre>(30);
    auto q2 = phy::Qty<phy::Metre>(30);
    EXPECT_TRUE(q1>=q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_TRUE(q1>=q3);
    EXPECT_FALSE(q3>=q1);
}

TEST(TestUnits, ComparaisonSuperiorOrEqualDifferentRatio){
    auto q1 = phy::Qty<phy::Metre,std::kilo>(3);
    auto q2 = phy::Qty<phy::Metre>(3000);
    EXPECT_TRUE(q1>=q2);
    auto q3 = phy::Qty<phy::Metre>(20);
    EXPECT_TRUE(q1>=q3);
    EXPECT_FALSE(q3>=q1);
}

TEST(TestUnits, CompareTwoDivs){
    auto l1 = 4_metres;
    auto l2 = 2_seconds;
    auto l3 = 2_metres;
    auto l4 = 1_seconds;
    auto res1 = l1 / l2;
    auto res2 = l3 / l4;
    EXPECT_TRUE(res1 == res2);
}

TEST(TestUnits, CompareTwoMults){
    auto l1 = 3_metres;
    auto l2 = 3_seconds;
    auto l3 = 3_metres;
    auto l4 = 3_seconds;
    auto res1 = l1 * l2;
    auto res2 = l3 * l4;
    EXPECT_TRUE(res1 == res2);
}
int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
