#include "Serial.h"
#include <limits>
#include <array>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <gtest/gtest.h>

const char* FileName = "FileTest.bin";
TEST(SerializationUint8, uint8BetweenBorders){
  uint8_t xBefore = 47;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint8_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}
TEST(SerializationUint8, uint8LowerBorder){
  uint8_t xBefore = std::numeric_limits<uint8_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint8_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}
TEST(SerializationUint8, uint8upperBorder){
    uint8_t xBefore = std::numeric_limits<uint8_t>::max();
    {
    serial::OBinaryFile serializer(FileName);
    serializer << xBefore;
    }
    uint8_t xAfter;
    serial::IBinaryFile deserializer(FileName);
    deserializer >> xAfter;
    EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt8, uint8eq0){
  int8_t xBefore = 0;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int8_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt8, uint8BetweenBorders){
  int8_t xBefore = 19;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int8_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt8, uint8LowerBorder){
  int8_t xBefore = std::numeric_limits<int8_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int8_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt8, uint8UpperBorder){
  int8_t xBefore = std::numeric_limits<int8_t>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int8_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint16, uint16BetweenBorders){
  uint16_t xBefore = 348;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint16_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint16, uint16LowerBorder){
  uint16_t xBefore = std::numeric_limits<uint16_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint16_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint16, uint16UpperBorder){
  uint16_t xBefore = std::numeric_limits<uint16_t>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint16_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt16, int16eq0){
  int16_t xBefore = 0;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int16_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt16, int16BetweenBorders){
  int16_t xBefore = 348;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int16_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt16, int16LowerBorder){
  int16_t xBefore = std::numeric_limits<int16_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int16_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt16, int16UpperBorder){
  int16_t xBefore = std::numeric_limits<int16_t>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int16_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint32, uint32BetweenBorders){
  uint32_t xBefore = 100000;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint32_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint32, uint32LowerBorder){
  uint32_t xBefore = std::numeric_limits<uint32_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint32_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint32, uint32UpperBorder){
  uint32_t xBefore = std::numeric_limits<uint32_t>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint32_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt32, int32eq0){
  int32_t xBefore = 0;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int32_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt32, int32BetweenBorders){
  int32_t xBefore = 100000;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int32_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt32, int32LowerBorder){
  int32_t xBefore = std::numeric_limits<int32_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int32_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt32, int32UpperBorder){
  int32_t xBefore = std::numeric_limits<int32_t>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int32_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint64, uint64BetweenBorders){
  uint64_t xBefore = 3584648912;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint64_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint64, uint64LowerBorder){
  uint64_t xBefore = std::numeric_limits<uint64_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint64_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationUint64, uint64UpperBorder){
  uint64_t xBefore = std::numeric_limits<uint64_t>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  uint64_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt64, int64eq0){
  int64_t xBefore = 0;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int64_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt64, int64BetweenBorders){
  int64_t xBefore = 3584648912;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int64_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt64, int64LowerBorder){
  int64_t xBefore = std::numeric_limits<int64_t>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int64_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationInt64, int64UpperBorder){
  int64_t xBefore = std::numeric_limits<int64_t>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  int64_t xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationChar, CharLowerBorder){
  char xBefore = std::numeric_limits<char>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  char xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationChar, CharUpperBorder){
  char xBefore = std::numeric_limits<char>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  char xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationChar, EveryChar){
  for(size_t i = 0; i <= 255; i++){
    char xBefore = (char)(i);
    {
    serial::OBinaryFile serializer(FileName);
    serializer << xBefore;
    }
    char xAfter;
    {
    serial::IBinaryFile deserializer(FileName);
    deserializer >> xAfter;
    EXPECT_EQ(xBefore, xAfter);
    }
  }
}

TEST(SerializationFloat, FloatEq0){
  float xBefore = 0.0;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  float xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_FLOAT_EQ(xBefore, xAfter);
}

TEST(SerializationFloat, FloatBetweenBorders){
  float xBefore = 5814.5151;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  float xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_FLOAT_EQ(xBefore, xAfter);
}

TEST(SerializationFloat, FloatLowerBorder){
  float xBefore = std::numeric_limits<float>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  float xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_FLOAT_EQ(xBefore, xAfter);
}

TEST(SerializationFloat, FloatUpperBorder){
  float xBefore = std::numeric_limits<float>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  float xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_FLOAT_EQ(xBefore, xAfter);
}

TEST(SerializationDouble, DoubleEq0){
  double xBefore = 0.0;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  double xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_DOUBLE_EQ(xBefore, xAfter);
}

TEST(SerializationDouble, DoubleBetweenBorders){
  double xBefore = 1548956.154862;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  double xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_DOUBLE_EQ(xBefore, xAfter);
}

TEST(SerializationDouble, DoubleLowerBorder){
  double xBefore = std::numeric_limits<double>::min();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  double xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_DOUBLE_EQ(xBefore, xAfter);
}

TEST(SerializationDouble, DoubleUpperBorder){
  double xBefore = std::numeric_limits<double>::max();
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  double xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_DOUBLE_EQ(xBefore, xAfter);
}

TEST(SerializationBool, BoolTrue){
  bool xBefore = true;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  bool xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_TRUE(xBefore && xAfter);
}

TEST(SerializationBool, BoolFalse){
  bool xBefore = false;
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  bool xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_TRUE(!xBefore && !xAfter);
}

TEST(SerializationString, StringNormal){
  std::string xBefore = "Avant, mon voisin habitait en face du cimetière, maintenant il habite en face de chez lui.";
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  std::string xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_TRUE(strcmp(xBefore.c_str(),xAfter.c_str())==0);
}

TEST(SerializationString, StringWithAntislashThings){
  std::string xBefore = "Alors! \n \t Vous le voulez oui ou non? \n Le trésor des sudistes!\0";
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  std::string xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_TRUE(strcmp(xBefore.c_str(),xAfter.c_str())==0);
}

TEST(SerializationString, StringWithWeirdChars){
  std::string xBefore = "♫Ç«£!▄▬ıQ╝♦♫▄F0%Q¸o1♪▼=œtØ1ÿ»Ï";
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  std::string xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_TRUE(strcmp(xBefore.c_str(),xAfter.c_str())==0);
}

TEST(SerializationString, StringEmptyChain){
  std::string xBefore = "";
  {
  serial::OBinaryFile serializer(FileName);
  serializer << xBefore;
  }
  std::string xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_TRUE(strcmp(xBefore.c_str(),xAfter.c_str())==0);
}

TEST(SerializationVector, VectorOfUint8){
	std::vector<uint8_t> xBefore = {0, 125, 255};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<uint8_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfInt8){
	std::vector<int8_t> xBefore = {-125, 0, 125};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<int8_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfUint16){
	std::vector<uint16_t> xBefore = {0, 300, 5000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<uint16_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfInt16){
	std::vector<int16_t> xBefore = {-1250, 0, 1250};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<int16_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfUint32){
	std::vector<uint32_t> xBefore = {0, 10000, 2000000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<uint32_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfInt32){
	std::vector<int32_t> xBefore = {-10000, 0 , 10000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<int32_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfUint64){
	std::vector<uint64_t> xBefore = {0, 500000000, 215619552};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<uint64_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfInt64){
	std::vector<int64_t> xBefore = {-215615415, 0 , 26488662};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<int64_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfBool){
	std::vector<bool> xBefore = {true, false, false, true, true, false, true};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<bool> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfChar){
	std::vector<char> xBefore = {'a','b','c','d','e'};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<char> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfFloat){
	std::vector<float> xBefore = {0.0, 545.0, 49465262.648};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<float> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfDouble){
	std::vector<double> xBefore = {0.0, 5415.0, 49465262.648};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<double> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationVector, VectorOfString){
	std::vector<std::string> xBefore = {"oui", "non", "peutetre"};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::vector<std::string> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}								

TEST(SerializationArray, ArrayOfUint8){
	std::array<uint8_t, 3> xBefore = {0, 125, 255};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<uint8_t, 3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfInt8){
	std::array<int8_t, 3> xBefore = {-125, 0, 125};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<int8_t, 3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfUint16){
	std::array<uint16_t,3> xBefore = {0, 300, 5000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<uint16_t,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfInt16){
	std::array<int16_t,3> xBefore = {-1250, 0, 1250};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<int16_t,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfUint32){
	std::array<uint32_t,3> xBefore = {0, 10000, 2000000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<uint32_t,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfInt32){
	std::array<int32_t,3> xBefore = {-10000, 0 , 10000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<int32_t,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfUint64){
	std::array<uint64_t,3> xBefore = {0, 500000000, 215619552561};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<uint64_t,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfInt64){
	std::array<int64_t,3> xBefore = {-215615415, 0 , 26488662};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<int64_t,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfBool){
	std::array<bool,7> xBefore = {true, false, false, true, true, false, true};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<bool,7> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfChar){
	std::array<char,5> xBefore = {'a','b','c','d','e'};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<char,5> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfFloat){
	std::array<float,3> xBefore = {0.0, 545.0, 49465262.648};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<float,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfDouble){
	std::array<double,3> xBefore = {0.0, 5415.0, 49465262.648};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<double,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationArray, ArrayOfString){
	std::array<std::string,3> xBefore = {"oui", "non", "peutetre"};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::array<std::string,3> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationMap, MapOfUint8){
	std::map<uint8_t, uint8_t> xBefore = { {0,8}, {10,125}, {20,255}};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::map<uint8_t, uint8_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}
/*
*	Comme vu précédemment, les tests sur les int/float/etc sont fonctionnels, alors plutôt que de les retester avec des maps, on va plutôt tester quelques couples seulement
*/

TEST(SerializationMap, MapKeyUint8ValueChar){
	std::map<uint8_t, char> xBefore = { {0,'a'}, {10,'g'}, {20,'z'}};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::map<uint8_t, char> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationMap, MapKeyStringValueBool){
	std::map<std::string, bool> xBefore = { {"oui",true}, {"non",false}, {"peutetre", true}};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::map<std::string, bool> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfUint8){
	std::set<uint8_t> xBefore = {0, 125, 255};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<uint8_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfInt8){
	std::set<int8_t> xBefore = {-125, 0, 125};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<int8_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfUint16){
	std::set<uint16_t> xBefore = {0, 300, 5000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<uint16_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfInt16){
	std::set<int16_t> xBefore = {-1250, 0, 1250};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<int16_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfUint32){
	std::set<uint32_t> xBefore = {0, 10000, 2000000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<uint32_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfInt32){
	std::set<int32_t> xBefore = {-10000, 0 , 10000};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<int32_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfUint64){
	std::set<uint64_t> xBefore = {0, 500000000, 215619552561};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<uint64_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfInt64){
	std::set<int64_t> xBefore = {-215615415, 0 , 26488662};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<int64_t> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfBool){
	std::set<bool> xBefore = {true, false, false, true, true, false, true};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<bool> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfChar){
	std::set<char> xBefore = {'a','b','c','d','e'};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<char> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfFloat){
	std::set<float> xBefore = {0.0, 545.0, 49465262.648};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<float> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfDouble){
	std::set<double> xBefore = {0.0, 5415.0, 49465262.648};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<double> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(SerializationSet, SetOfString){
	std::set<std::string> xBefore = {"oui", "non", "peutetre"};
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	std::set<std::string> xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}

TEST(ConstructorTests, OBinaryFileNotExist){
	EXPECT_THROW(serial::OBinaryFile serializer("/jexistepo/moinonplus"), std::runtime_error);
}
TEST(ConstructorTests, IBinaryFileNotExist){
	EXPECT_THROW(serial::IBinaryFile serializer("/jexistepo/moinonplus"), std::runtime_error);
}
/*TEST(ConstructorTests, OBinaryFileIBinaryFileMoveAssignement){
	uint8_t xBefore = 1;
	{
	serial::OBinaryFile serializer(FileName);
	serial::OBinaryFile theRealSerializer = std::move(serializer);
	theRealSerializer << xBefore;
	}
	uint8_t xAfter;
	serial::IBinaryFile deserializer(FileName);
	serial::IBinaryFile theRealDeserializer = std::move(deserializer);
	theRealDeserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}*/

/*TEST(ConstructorTests, OBinaryFileIBinaryFileMoveAssignement){
	uint8_t xBefore = 1;
	{
	serial::OBinaryFile serializer(FileName);
	serial::OBinaryFile theRealSerializer = serializer;
	theRealSerializer << xBefore;
	}
	uint8_t xAfter;
	serial::IBinaryFile deserializer(FileName);
	serial::IBinaryFile theRealDeserializer(deserializer);
	deserializer >> xAfter;
	EXPECT_EQ(xBefore, xAfter);
}*/

TEST(ConstructorTests, OBinaryFileConcat){
	char xBefore = 'a';
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	{
	serial::OBinaryFile ConcatSerializer(FileName, serial::OBinaryFile::Mode::Append);
	xBefore = 'b';
	ConcatSerializer << xBefore;
	}
	char xAfter1;
	char xAfter2;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter1;
	deserializer >> xAfter2;
	EXPECT_EQ('a', xAfter1);
	EXPECT_EQ('b', xAfter2);
}

TEST(ConstructorTests, OBinaryFileTruncate){
	char xBefore = 'a';
	{
	serial::OBinaryFile serializer(FileName);
	serializer << xBefore;
	}
	{
	serial::OBinaryFile ConcatSerializer(FileName, serial::OBinaryFile::Mode::Truncate);
	xBefore = 'b';
	ConcatSerializer << xBefore;
	}
	char xAfter;
	serial::IBinaryFile deserializer(FileName);
	deserializer >> xAfter;
	EXPECT_EQ('b', xAfter);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
