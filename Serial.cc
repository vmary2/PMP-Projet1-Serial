#include "Serial.h"

namespace serial {

/***********************************************************
 *                      RULE OF FIVE
 ***********************************************************/

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


/***********************************************************
 *                            READ UTILITY
 ***********************************************************/


std::size_t IBinaryFile::read(std::byte* data, std::size_t size){
    return std::fread(data, sizeof(std::byte), size, m_file);
}


/***********************************************************
 *                            READ OPERATORS
 ***********************************************************/


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
IBinaryFile& operator>>(IBinaryFile& file, float& x);
IBinaryFile& operator>>(IBinaryFile& file, double& x);
IBinaryFile& operator>>(IBinaryFile& file, bool& x){
    std::byte ret;
    file.read(&ret, 1);
    x = (std::to_integer<char>(ret) != 0);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, std::string& x){
    // Read the size of the string
    uint64_t sz; file >> sz;
    char tmp[sz];
    // Creation of the C string byte per byte including the final '\0'
    for(uint64_t i = 0 ; i < sz ; i++){
        file >> tmp[i];
    }
    x = tmp;
    return file;
}

}       // End of namespace serial