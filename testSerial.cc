#include "Serial.h"
#include <limits>
#include <gtest/gtest.h>

const char* FileName = "FileTest.txt";
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
  for(size_t i = 0; i <= 127; i++){
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
  float xAfter;
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
  float xAfter;
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
  float xAfter;
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
  float xAfter;
  serial::IBinaryFile deserializer(FileName);
  deserializer >> xAfter;
  EXPECT_DOUBLE_EQ(xBefore, xAfter);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
