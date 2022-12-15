#include <libxdt.hpp>

#include <map>
#include <fstream>
#include <vector>
#include <iterator>

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

    #pragma region items
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
    #pragma endregion

    outTable.directory = {
        {"byte", srcItem_Byte},
        {"bool", srcItem_Bool},
        {"int16", srcItem_Int16},
        {"uint16", srcItem_Uint16},
        {"int32", srcItem_Int32},
        {"uint32", srcItem_Uint32},
        {"int64", srcItem_Int64},
        {"uint64", srcItem_Uint64},
        {"float", srcItem_Float},
        {"double", srcItem_Double},
        {"timestamp", srcItem_Timestamp},
        {"long_timestamp", srcItem_LongTimestamp},
        {"string (ascii)", srcItem_ASCIIString},
        {"string (utf-8)", srcItem_UTF8String},
        {"file", srcItem_File},
        {"raw", srcItem_Raw}
    };

    auto outBytes = outTable.Serialise();

    std::ofstream f_out("out.xdt", std::ios::binary);
    for(auto b : outBytes) { f_out << b; }

    std::cout << "Wrote " << outBytes.size() << " bytes to file 'out.xdt'." << std::endl;

    f_out.close();

    // Input
    std::ifstream f_in("out.xdt", std::ios::binary);

    auto inBytes = std::vector<uint8_t>(
        std::istreambuf_iterator<char>(f_in),
        std::istreambuf_iterator<char>()
    );

    f_in.close();

    std::cout << "Read " << inBytes.size() << " bytes." << std::endl;

    xdt::Table inTable;
    inTable.Deserialise(inBytes);

    if(!inTable.errorStatus.empty()) {
        std::cout << "error: " << inTable.errorStatus << std::endl;
    }else {
        for(auto &[name, item] : inTable.directory) {
            std::cout << "(" << xdt::GetTypeString(item.type) << ") \"" << name << "\":\n";

            bool isBlob = (item.type == xdt::ItemType::File) || (item.type == xdt::ItemType::Raw);

            if(isBlob) {
                std::cout << "\tValue: <" << item.data.size() << " bytes>" << std::endl;
            }else {
                std::cout << "\tValue: " << item.GetString(item.type == xdt::ItemType::Byte) << std::endl;
            }
        }
    }
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout   << "Please pass one of the following numbers as an argument to demo a specific function:\n" << std::endl;
        std::cout   << "1. Casting\n"
                    << "2. File IO\n"
                    << std::endl;
        return 0;
    }

    int selection = std::atoi(argv[1]);

    switch(selection) {
        case 1: CastingDemo();  break;
        case 2: FileIODemo();   break;
        default:
            std::cout << "Invalid demo." << std::endl;
    }

    return 0;
}