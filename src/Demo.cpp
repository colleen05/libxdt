#include <libxdt.hpp>

#include <map>
#include <fstream>
#include <vector>
#include <iterator>
#include <time.h>

void CastingDemo() {
    xdt::Item srcItem_Byte;
    srcItem_Byte.SetByte(0x69, true);
    xdt::Item srcItem_Bool;
    srcItem_Bool.SetBool(true, true);
    xdt::Item srcItem_Int16;
    srcItem_Int16.SetInt16(-1337, true);
    xdt::Item srcItem_Uint16;
    srcItem_Uint16.SetUint16(42069, true);
    xdt::Item srcItem_Int32;
    srcItem_Int32.SetInt32(-8008135, true);
    xdt::Item srcItem_Uint32;
    srcItem_Uint32.SetUint32(12345, true);
    xdt::Item srcItem_Int64;
    srcItem_Int64.SetInt64(-987654321, true);
    xdt::Item srcItem_Uint64;
    srcItem_Uint64.SetUint64(11235813, true);
    xdt::Item srcItem_Float;
    srcItem_Float.SetFloat(3.14159f, true);
    xdt::Item srcItem_Double;
    srcItem_Double.SetDouble(-0.012345, true);
    xdt::Item srcItem_Timestamp;
    srcItem_Timestamp.SetTimestamp(std::chrono::seconds(1670971965), false, true);
    xdt::Item srcItem_LongTimestamp;
    srcItem_LongTimestamp.SetTimestamp(std::chrono::seconds(1670971965), true, true);
    xdt::Item srcItem_ASCIIString;
    srcItem_ASCIIString.SetString("Hello, world!", false, true);
    xdt::Item srcItem_UTF8String;
    srcItem_UTF8String.SetString("Cats🐈 are cool! 💖", true, true);
    xdt::Item srcItem_File;
    std::string fileString = "#include <stdio.h>\n\nint main() {\n printf(\"Hello, world!\");\n}";
    srcItem_File.SetBytes(std::vector<uint8_t>(fileString.begin(), fileString.end()), true, true);
    xdt::Item srcItem_Raw;
    srcItem_Raw.SetBytes({0x12, 0x34, 0x56, 0x78, 0x9A}, false, true);

    std::vector<std::pair<std::string, xdt::Item*>> items = {
        {"byte", &srcItem_Byte},
        {"bool", &srcItem_Bool},
        {"int16", &srcItem_Int16},
        {"uint16", &srcItem_Uint16},
        {"int32", &srcItem_Int32},
        {"uint32", &srcItem_Uint32},
        {"int64", &srcItem_Int64},
        {"uint64", &srcItem_Uint64},
        {"float", &srcItem_Float},
        {"double", &srcItem_Double},
        {"timestamp", &srcItem_Timestamp},
        {"long_timestamp", &srcItem_LongTimestamp},
        {"string (ascii)", &srcItem_ASCIIString},
        {"string (utf-8)", &srcItem_UTF8String},
        {"file", &srcItem_File},
        {"raw", &srcItem_Raw}
    };

    for(auto &[name, ptr] : items) {
        std::cout << name << " as:" << std::endl;

        std::cout << "\tbyte:      " << (int)ptr->GetByte() << std::endl;
        std::cout << "\tbool:      " << (ptr->GetBool() ? "true" : "false") << std::endl;
        std::cout << "\tint16:     " << ptr->GetInt16() << std::endl;
        std::cout << "\tuint16:    " << ptr->GetUint16() << std::endl;
        std::cout << "\tint32:     " << ptr->GetInt32() << std::endl;
        std::cout << "\tuint32:    " << ptr->GetUint32() << std::endl;
        std::cout << "\tint64:     " << ptr->GetInt64() << std::endl;
        std::cout << "\tuint64:    " << ptr->GetUint64() << std::endl;
        std::cout << "\tfloat:     " << ptr->GetFloat() << std::endl;
        std::cout << "\tdouble:    " << ptr->GetDouble() << std::endl;
        std::cout << "\ttimestamp: " << ptr->GetTimestamp().count() << std::endl;
        std::cout << "\tstring:    \"" << ptr->GetString(ptr->type == xdt::ItemType::Byte) << "\"" << std::endl;
        std::cout << "\traw:       <" << ptr->GetBytes().size() << " bytes>" << std::endl;
    }
}

void FileIODemo() {
    xdt::Table outTable;

    std::string fileString = "#include <stdio.h>\n\nint main() {\n printf(\"Hello, world!\");\n}";

    for(int i = 0; i < 4095; i++) {
        outTable.SetByte        (std::to_string(i) + "my_byte",             0x69,       true);
        outTable.SetBool        (std::to_string(i) + "my_bool",             true,       true);
        outTable.SetInt16       (std::to_string(i) + "my_int16",            -1337,      true);
        outTable.SetUint16      (std::to_string(i) + "my_uint16",           42069,      true);
        outTable.SetInt32       (std::to_string(i) + "my_int32",            -8008135,   true);
        outTable.SetUint32      (std::to_string(i) + "my_uint32",           12345,      true);
        outTable.SetInt64       (std::to_string(i) + "my_int64",            -987654321, true);
        outTable.SetUint64      (std::to_string(i) + "my_uint64",           11235813,   true);
        outTable.SetFloat       (std::to_string(i) + "my_float",            3.14159f,   true);
        outTable.SetDouble      (std::to_string(i) + "my_double",           -0.012345,  true);
        outTable.SetTimestamp   (std::to_string(i) + "my_timestamp",        std::chrono::seconds(1670971965),   false,  true);
        outTable.SetTimestamp   (std::to_string(i) + "my_long_timestamp",   std::chrono::seconds(1670971965),   true,   true);
        outTable.SetString      (std::to_string(i) + "my_string",           "Hello, world!",                    false,  true);
        outTable.SetString      (std::to_string(i) + "my_utf8_string",      "Cats🐈 are cool! 💖",              true,   true);
        outTable.SetBytes       (std::to_string(i) + "my_file_data",        std::vector<uint8_t>(fileString.begin(), fileString.end()), true, true);
        outTable.SetBytes       (std::to_string(i) + "my_raw_data",         {0x12, 0x34, 0x56, 0x78, 0x9A}, false, true);
    }

    clock_t serialiseTimer_start = clock();
    auto outBytes = outTable.Serialise();
    clock_t serialiseTimer_end = clock();

    std::ofstream f_out("out.xdt", std::ios::binary);
    for(auto b : outBytes) { f_out << b; }

    clock_t serialiseTimer_end2 = clock();

    std::cout << "Wrote " << outBytes.size() << " bytes to file 'out.xdt'." << std::endl;

    f_out.close();

    // Input
    clock_t deserialiseTimer_start2 = clock();
    std::ifstream f_in("out.xdt", std::ios::binary);

    auto inBytes = std::vector<uint8_t>(
        std::istreambuf_iterator<char>(f_in),
        std::istreambuf_iterator<char>()
    );

    f_in.close();

    std::cout << "Read " << inBytes.size() << " bytes." << std::endl;

    xdt::Table inTable;
    
    clock_t deserialiseTimer_start = clock();
    inTable.Deserialise(inBytes);
    clock_t deserialiseTimer_end = clock();

    if(!inTable.errorStatus.empty()) {
        std::cout << "error: " << inTable.errorStatus << std::endl;
    }else {
        for(auto &[name, item] : inTable.directory) {
            std::cout << "(" << xdt::GetTypeString(item.type) << ") \"" << name << "\": ";

            bool isBlob = (item.type == xdt::ItemType::File) || (item.type == xdt::ItemType::Raw);

            if(isBlob) {
                std::cout << "<" << item.data.size() << " bytes>" << std::endl;
            }else {
                std::cout << item.GetString(item.type == xdt::ItemType::Byte) << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;

    std::cout << "              Items: " << std::to_string(inTable.directory.size()) << "." << std::endl;
    std::cout << "          File Size: " << std::to_string(inBytes.size() / 1024) << "kb." << std::endl;
    std::cout << "  Time to serialise: " << ((serialiseTimer_end - serialiseTimer_start)      / (double)CLOCKS_PER_SEC) * 1000.0 << "ms." << std::endl;
    std::cout << "        +File write: " << ((serialiseTimer_end2 - serialiseTimer_start)     / (double)CLOCKS_PER_SEC) * 1000.0 << "ms." << std::endl;
    std::cout << "Time to deserialise: " << ((deserialiseTimer_end - deserialiseTimer_start)  / (double)CLOCKS_PER_SEC) * 1000.0 << "ms." << std::endl;
    std::cout << "         +File read: " << ((deserialiseTimer_end - deserialiseTimer_start2) / (double)CLOCKS_PER_SEC) * 1000.0 << "ms." << std::endl;
}

void RLEDemo() {
    std::string srcString = "Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA                               BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   !!!!!!!Hello   AAAAAABBBBBBBBBBBBBB   World!!!!!!!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello   AAAAAA              BBBBBBBBBBBBBB   World!!!Hello              BBBBBBBBBBBBBBBBBBBBBBBBBBBB   World!!!";
    auto srcBytes = std::vector<uint8_t>(srcString.begin(), srcString.end());

    clock_t encodeTimer_start = clock();
    auto compressedBytes = xdt::CompressRLE(srcBytes);
    clock_t encodeTimer_end = clock();

    clock_t decodeTimer_start = clock();
    auto decompressedBytes = xdt::DecompressRLE(compressedBytes);
    clock_t decodeTimer_end = clock();

    std::cout << "       Source size: <" << srcBytes.size() << " bytes>" << std::endl;
    std::cout << "   Compressed size: <" << compressedBytes.size() << " bytes>" << std::endl;
    std::cout << "  Time to compress: " << (encodeTimer_end - encodeTimer_start) / (double)CLOCKS_PER_SEC * 1000.0 << "ms." << std::endl;
    std::cout << "Time to decompress: " << (decodeTimer_end - decodeTimer_start) / (double)CLOCKS_PER_SEC * 1000.0 << "ms." << std::endl;

    std::cout << std::endl;

    std::cout << "Check: " << ((srcBytes == decompressedBytes) ? "SUCCESS" : "FAIL") << std::endl;
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout   << "Please pass one of the following numbers as an argument to demo a specific function:\n" << std::endl;
        std::cout   << "1. Casting\n"
                    << "2. File IO\n"
                    << "3. RLE\n"
                    << std::endl;
        return 0;
    }

    int selection = std::atoi(argv[1]);

    switch(selection) {
        case 1: CastingDemo();  break;
        case 2: FileIODemo();   break;
        case 3: RLEDemo();      break;
        default:
            std::cout << "Invalid demo." << std::endl;
    }

    return 0;
}