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
    std::size_t ret = std::fread(data, sizeof(std::byte), size, m_file);
}


/***********************************************************
 *                            READ OPERATORS
 ***********************************************************/


IBinaryFile& operator>>(IBinaryFile& file, int8_t& x){
    file.read((std::byte *)x, 1);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, uint8_t& x){
    file.read((std::byte *)x, 1);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, int16_t& x){
    std::byte t[2];
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, uint16_t& x);
IBinaryFile& operator>>(IBinaryFile& file, int32_t& x);
IBinaryFile& operator>>(IBinaryFile& file, uint32_t& x);
IBinaryFile& operator>>(IBinaryFile& file, int64_t& x);
IBinaryFile& operator>>(IBinaryFile& file, uint64_t& x);
IBinaryFile& operator>>(IBinaryFile& file, char& x);
IBinaryFile& operator>>(IBinaryFile& file, float& x);
IBinaryFile& operator>>(IBinaryFile& file, double& x);
IBinaryFile& operator>>(IBinaryFile& file, bool& x){
    std::byte ret;
    file.read(&ret, 1);
    x = (std::to_integer<char>(ret) != 0);
    return file;
}
IBinaryFile& operator>>(IBinaryFile& file, std::string& x);

}
