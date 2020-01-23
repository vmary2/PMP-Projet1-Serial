#include "Serial.h"
#include <cstring>

static_assert(sizeof(float) == sizeof(uint32_t) && sizeof(double) == sizeof(uint64_t));

namespace serial {

/**********************************************************************************
 *                                   RULE OF FIVE
 **********************************************************************************/

IBinaryFile::IBinaryFile(const std::string& filename)
    : m_file(std::fopen(filename.c_str(), "rb")){

    if(nullptr == m_file){
        throw std::runtime_error ("Error attempting to read the file");
    }
}

IBinaryFile::IBinaryFile(IBinaryFile&& other) noexcept
    : m_file(std::exchange(other.m_file, nullptr)){}

IBinaryFile::~IBinaryFile(){
    std::fclose(m_file);
}

IBinaryFile& IBinaryFile::operator=(IBinaryFile&& other) noexcept{
    std::swap(other.m_file, m_file);
    return *this;
}


/**********************************************************************************
 *                                  READ UTILITY
 **********************************************************************************/


std::size_t IBinaryFile::read(std::byte* data, std::size_t size){
    return std::fread(data, sizeof(std::byte), size, m_file);
}


/**********************************************************************************
 *                                 READ OPERATORS
 **********************************************************************************/


IBinaryFile& operator>>(IBinaryFile& file, int8_t& x){
    std::byte t;
    file.read(&t, 1);
    x = std::to_integer<int8_t>(t);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, uint8_t& x){
    std::byte t;
    file.read(&t, 1);
    x = std::to_integer<uint8_t>(t);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, int16_t& x){
    std::byte t[2];
    file.read(t, 2);
    x = std::to_integer<int16_t>(t[0])<<8 | std::to_integer<int16_t>(t[1]);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, uint16_t& x){
    std::byte t[2];
    file.read(t, 2);
    x = std::to_integer<uint16_t>(t[0])<<8 | std::to_integer<uint16_t>(t[1]);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, int32_t& x){
    std::byte t[4];
    file.read(t, 4);
    x = std::to_integer<int32_t>(t[0])<<24 | std::to_integer<int32_t>(t[1])<<16
      | std::to_integer<int32_t>(t[2])<<8  | std::to_integer<int32_t>(t[3]);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, uint32_t& x){
    std::byte t[4];
    file.read(t, 4);
    x = std::to_integer<uint32_t>(t[0])<<24 | std::to_integer<uint32_t>(t[1])<<16
      | std::to_integer<uint32_t>(t[2])<<8  | std::to_integer<uint32_t>(t[3]);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, int64_t& x){
    std::byte t[8];
    file.read(t, 8);
    x = std::to_integer<int64_t>(t[0])<<56 | std::to_integer<int64_t>(t[1])<<48
      | std::to_integer<int64_t>(t[2])<<40 | std::to_integer<int64_t>(t[3])<<32
      | std::to_integer<int64_t>(t[4])<<24 | std::to_integer<int64_t>(t[5])<<16
      | std::to_integer<int64_t>(t[6])<<8  | std::to_integer<int64_t>(t[7]);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, uint64_t& x){
    std::byte t[8];
    file.read(t, 8);
    x = std::to_integer<uint64_t>(t[0])<<56 | std::to_integer<uint64_t>(t[1])<<48
      | std::to_integer<uint64_t>(t[2])<<40 | std::to_integer<uint64_t>(t[3])<<32
      | std::to_integer<uint64_t>(t[4])<<24 | std::to_integer<uint64_t>(t[5])<<16
      | std::to_integer<uint64_t>(t[6])<<8  | std::to_integer<uint64_t>(t[7]);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, char& x){
    std::byte t;
    file.read(&t, 1);
    x = std::to_integer<char>(t);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, float& x){
    // On récupère le binaire du float stockés dans un entier 32 bits
    uint32_t raw; file >> raw;
    float rawd;
    std::memcpy(&rawd, &raw, sizeof(uint32_t));
    x = rawd;
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, double& x){
    // On récupère le binaire du float stockés dans un entier 64 bits
    uint64_t raw; file >> raw;
    double rawd;
    std::memcpy(&rawd, &raw, sizeof(uint64_t));
    x = rawd;
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, bool& x){
    std::byte ret;
    file.read(&ret, 1);
    x = std::to_integer<bool>(ret);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, std::string& x){
    // Read the size of the string
    uint64_t sz; 
    file >> sz;
    char tmp[sz+1];
    // Creation of the C string byte per byte including the final '\0'
    for(uint64_t i = 0 ; i < sz ; i++){
        file >> tmp[i];
    }
    tmp[sz] = '\0';
    x = tmp;
    return file;
}

/***********************************************************
 *                    OBinaryFile
 ***********************************************************/
/***********************************************************
 *                      RULE OF FIVE
 ***********************************************************/

OBinaryFile::OBinaryFile(const std::string& filename, OBinaryFile::Mode mode)
    : m_file(mode == Truncate ? std::fopen(filename.c_str(), "wb") : std::fopen(filename.c_str(), "ab")){
        if (m_file == nullptr){
            throw std::runtime_error ("Error while opening the file");
        }
    }

OBinaryFile::OBinaryFile(OBinaryFile&& other) noexcept
    : m_file(std::exchange(other.m_file, m_file)){}

OBinaryFile& OBinaryFile::operator=(OBinaryFile&& other) noexcept{
    std::swap(other.m_file, m_file);
    return *this;
}

OBinaryFile::~OBinaryFile(){
    std::fclose(m_file);
}

/***********************************************************
 *                     WRITE UTILITY
 ***********************************************************/
std::size_t OBinaryFile::write(const std::byte* data, std::size_t size){
    return fwrite(data, sizeof(std::byte),size, m_file);
}

/***********************************************************
 *                     WRITE OPERATORS
 ***********************************************************/

OBinaryFile& operator<<(OBinaryFile& file, uint8_t x){
    std::byte xBigEndian = static_cast<std::byte>(x);
    file.write(&xBigEndian, 1);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, int8_t x){
    std::byte xBigEndian = static_cast<std::byte>(x);
    file.write(&xBigEndian, 1);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, uint16_t x){
    std::byte xBigEndian[2];
    xBigEndian[1] = static_cast<std::byte>(x & 0xff);
    xBigEndian[0] = static_cast<std::byte>(x >> 8 & 0xff);
    file.write(xBigEndian, 2);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, int16_t x){
    std::byte xBigEndian [2];
    xBigEndian[1] = static_cast<std::byte>(x & 0xff);
    xBigEndian[0] = static_cast<std::byte>(x >> 8 & 0xff);
    file.write(xBigEndian, 2);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, uint32_t x){
    std::byte xBigEndian [4];
    xBigEndian[3] = static_cast<std::byte>(x & 0xff);
    xBigEndian[2] = static_cast<std::byte>(x >> 8 & 0xff);
    xBigEndian[1] = static_cast<std::byte>(x >> 16 & 0xff);
    xBigEndian[0] = static_cast<std::byte>(x >> 24 & 0xff);
    file.write(xBigEndian, 4);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, int32_t x){
    std::byte xBigEndian [4];
    xBigEndian[3] = static_cast<std::byte>(x & 0xff);
    xBigEndian[2] = static_cast<std::byte>(x >> 8 & 0xff);
    xBigEndian[1] = static_cast<std::byte>(x >> 16 & 0xff);
    xBigEndian[0] = static_cast<std::byte>(x >> 24 & 0xff);
    file.write(xBigEndian, 4);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, uint64_t x){
    std::byte xBigEndian [8];
    xBigEndian[7] = static_cast<std::byte>(x & 0xff);
    xBigEndian[6] = static_cast<std::byte>(x >> 8 & 0xff);
    xBigEndian[5] = static_cast<std::byte>(x >> 16 & 0xff);
    xBigEndian[4] = static_cast<std::byte>(x >> 24 & 0xff);
    xBigEndian[3] = static_cast<std::byte>(x >> 32 & 0xff);
    xBigEndian[2] = static_cast<std::byte>(x >> 40 & 0xff);
    xBigEndian[1] = static_cast<std::byte>(x >> 48 & 0xff);
    xBigEndian[0] = static_cast<std::byte>(x >> 56 & 0xff);
    file.write(xBigEndian, 8);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, int64_t x){
    std::byte xBigEndian [8];
    xBigEndian[7] = static_cast<std::byte>(x & 0xff);
    xBigEndian[6] = static_cast<std::byte>(x >> 8 & 0xff);
    xBigEndian[5] = static_cast<std::byte>(x >> 16 & 0xff);
    xBigEndian[4] = static_cast<std::byte>(x >> 24 & 0xff);
    xBigEndian[3] = static_cast<std::byte>(x >> 32 & 0xff);
    xBigEndian[2] = static_cast<std::byte>(x >> 40 & 0xff);
    xBigEndian[1] = static_cast<std::byte>(x >> 48 & 0xff);
    xBigEndian[0] = static_cast<std::byte>(x >> 56 & 0xff);
    file.write(xBigEndian, 8);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, char x){
    std::byte xBigEndian = std::byte(x);
    file.write(&xBigEndian, 1);
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, float x){
    uint32_t raw;
    std::memcpy(&raw, &x, sizeof(uint32_t));
    file << raw;
    return file;
}
OBinaryFile& operator<<(OBinaryFile& file, double x){
    uint64_t raw;
    std::memcpy(&raw, &x, sizeof(uint64_t));
    file << raw;
    return file;
}

OBinaryFile& operator<<(OBinaryFile& file, bool x){
    std::byte t = std::byte(true);
    std::byte f = std::byte(false);
    file.write(x ? &t : &f, 1);
    return file;
}

OBinaryFile& operator<<(OBinaryFile& file, const std::string& x){
    uint64_t size = x.size();
    file << size;
    for(std::size_t i = 0; i < size; i ++){
        file << x[i]; 
    }
    return file;
}

}       // End of namespace serial
