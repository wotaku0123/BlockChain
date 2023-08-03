#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    std::string input = "test";
    std::string output = sha256(input);
    std::cout << "SHA256(" << input << ") = " << output << std::endl;
    return 0;
}
