#include "Serial.h"

#include <gtest/gtest.h>

const char* FileName = "FileTest.txt";
TEST(SerialTests, uint8){
    
    double x = 186.95264;
    {
    printf("res avant sérialisation : %f\n", x);
    serial::OBinaryFile serializer(FileName);
    serializer << x;
    }
    
    double xAfter;
    serial::IBinaryFile deserializer(FileName);
    deserializer >> xAfter;
    printf("res après sérialisaiton : %f\n", xAfter);
    


}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
