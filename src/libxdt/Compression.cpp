#include <libxdt.hpp>

std::vector<uint8_t> xdt::CompressRLE(std::vector<uint8_t> &bytes) {
    const size_t srcSize = bytes.size();

    std::vector<uint8_t> out;
    out.reserve(srcSize);
    
    for(auto i = 0; i < srcSize; i++) {
        size_t count = 1;

        const auto &curByte = bytes[i];
        while((i < srcSize - 1) && (count < 0x100) && (curByte == bytes[i + 1])) {
            count++;
            i++;
        }

        out.push_back(curByte);
        out.push_back(count);
    }

    return out;
}

std::vector<uint8_t> xdt::DecompressRLE(std::vector<uint8_t> &bytes) {
    const size_t srcSize  = bytes.size();

    std::vector<uint8_t> out;
    out.reserve(2 * srcSize);

    for(auto i = 0; i < srcSize; i += 2) {
        const auto &repByte  = bytes[i];   
        const auto &repCount = bytes[i+1];

        for(auto j = 0; j < repCount; j++) out.push_back(repByte);
    }

    return out;
}