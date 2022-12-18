#include <libxdt.hpp>

// General item stuff
xdt::Item *xdt::Table::GetItem(std::string itemName) {
    for(auto &[name, item] : directory) {
        if(name == itemName) return &item;
    }

    return nullptr;
}

bool xdt::Table::ItemExists(std::string itemName) {
    return (GetItem(itemName) != nullptr);
}

xdt::ItemType xdt::Table::GetItemType(std::string itemName) {
    auto item = GetItem(itemName);

    return item ? item->type : xdt::ItemType::Byte;
}

// Getters
uint8_t xdt::Table::GetByte(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetByte() : 0x00;
}

bool xdt::Table::GetBool(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetBool() : 0x00;
}

int16_t xdt::Table::GetInt16(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetInt16() : 0x00;
}

uint16_t xdt::Table::GetUint16(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetUint16() : 0x00;
}

int32_t xdt::Table::GetInt32(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetInt32() : 0x00;
}

uint32_t xdt::Table::GetUint32(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetUint32() : 0x00;
}

int64_t xdt::Table::GetInt64(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetInt64() : 0x00;
}

uint64_t xdt::Table::GetUint64(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetUint64() : 0x00;
}

float xdt::Table::GetFloat(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetFloat() : 0x00;
}

double xdt::Table::GetDouble(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetDouble() : 0x00;
}

std::chrono::seconds xdt::Table::GetTimestamp(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetTimestamp() : std::chrono::seconds(0);
}

std::string xdt::Table::GetString(const std::string &itemName, bool asHex) {
    auto item = GetItem(itemName);
    return item ? item->GetString(asHex) : "";
}

std::vector<uint8_t> xdt::Table::GetBytes(const std::string &itemName) {
    auto item = GetItem(itemName);
    return item ? item->GetBytes() : std::vector<uint8_t>();
}

// Setters
void xdt::Table::SetByte(const std::string &itemName, uint8_t value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetByte(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetByte(value, overwriteType);
    }
}

void xdt::Table::SetBool(const std::string &itemName, bool value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetBool(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetBool(value, overwriteType);
    }
}

void xdt::Table::SetInt16(const std::string &itemName, int16_t value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetInt16(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetInt16(value, overwriteType);
    }
}

void xdt::Table::SetUint16(const std::string &itemName, uint16_t value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetUint16(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetUint16(value, overwriteType);
    }
}

void xdt::Table::SetInt32(const std::string &itemName, int32_t value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetInt32(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetInt32(value, overwriteType);
    }
}

void xdt::Table::SetUint32(const std::string &itemName, uint32_t value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetUint32(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetUint32(value, overwriteType);
    }
}

void xdt::Table::SetInt64(const std::string &itemName, int64_t value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetInt64(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetInt64(value, overwriteType);
    }
}

void xdt::Table::SetUint64(const std::string &itemName, uint64_t value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetUint64(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetUint64(value, overwriteType);
    }
}

void xdt::Table::SetFloat(const std::string &itemName, float value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetFloat(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetFloat(value, overwriteType);
    }
}

void xdt::Table::SetDouble(const std::string &itemName, double value, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetDouble(value, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetDouble(value, overwriteType);
    }
}

void xdt::Table::SetTimestamp(const std::string &itemName, std::chrono::seconds value, bool isLong, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetTimestamp(value, isLong, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetTimestamp(value, isLong, overwriteType);
    }
}

void xdt::Table::SetString(const std::string &itemName, const std::string &value, bool isUTF8, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetString(value, isUTF8, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetString(value, isUTF8, overwriteType);
    }
}

void xdt::Table::SetBytes(const std::string &itemName, const std::vector<uint8_t> &value, bool isFileData, bool overwriteType) {
    auto item = GetItem(itemName);

    if(item == nullptr) {
        item = new Item {};
        item->SetBytes(value, isFileData, true);
        directory.push_back(std::make_pair(itemName, *item));
    }else {
        item->SetBytes(value, isFileData, overwriteType);
    }
}

// Serialisation
std::vector<uint8_t> xdt::Table::Serialise() {
    //*** Section byte vectors ***//
    std::vector<uint8_t> xdtData;
    std::vector<uint8_t> headerData;
    std::vector<uint8_t> directoryData;
    std::vector<uint8_t> blobData;


    //*** Header ***//
    // Push magic word -- NO SPECIFIC ENDIANNESS
    headerData.push_back((XDT_MAGIC & 0xFF000000) >> 24);
    headerData.push_back((XDT_MAGIC & 0x00FF0000) >> 16);
    headerData.push_back((XDT_MAGIC & 0x0000FF00) >> 8);
    headerData.push_back((XDT_MAGIC & 0x000000FF) >> 0);

    // Push version -- NO SPECIFIC ENDIANNESS
    headerData.push_back((headerInfo.version & 0xFF00) >> 8);
    headerData.push_back((headerInfo.version & 0x00FF) >> 0);

    // Push flags -- LITTLE-ENDIAN
    headerData.push_back(headerInfo.flags.low);
    headerData.push_back(headerInfo.flags.high);

    // Push item count
    auto itemCount = directory.size();
    if(itemCount > 65535) return {};

    headerData.push_back(((uint16_t)(itemCount) & 0x00FF) >> 0);
    headerData.push_back(((uint16_t)(itemCount) & 0xFF00) >> 8);


    //*** Items ***//
    for(auto &[name, item] : directory) {
        if(name.length() > 255) return {};

        // Push name length
        directoryData.push_back((uint8_t)name.length());

        // Push name
        for(auto c : name) {
            directoryData.push_back(c);
        }

        // Push type
        directoryData.push_back((uint8_t)item.type);

        // Push value/size
        bool isBlob = (std::find(BLOBTypes.begin(), BLOBTypes.end(), item.type) != BLOBTypes.end());

        if(isBlob) {
            // Append value data to blob section
            if(XDT_GET_ITEM_COMPRESION(item.flags) == 0b01) {
                std::vector<uint8_t> compressed = CompressRLE(item.data);
                blobData.insert(blobData.end(), compressed.begin(), compressed.end());
            }else {
                blobData.insert(blobData.end(), item.data.begin(), item.data.end());
            }

            // Push BLOB size to directory entry -- LITTLE-ENDIAN
            auto blobsize = item.data.size();
            if(blobsize >= UINT32_MAX) return {0x00};

            directoryData.push_back((blobsize & 0x000000FF) >> 0);
            directoryData.push_back((blobsize & 0x0000FF00) >> 8);
            directoryData.push_back((blobsize & 0x00FF0000) >> 16);
            directoryData.push_back((blobsize & 0xFF000000) >> 24);
        }else {
            directoryData.insert(directoryData.end(), item.data.begin(), item.data.end());  // Append value data to directory entry
            directoryData.resize(directoryData.size() + (4 - item.data.size()), 0x00);      // Make up for rest of bytes
        }

        // Push flags -- LITTLE-ENDIAN
        directoryData.push_back(item.flags.low);
        directoryData.push_back(item.flags.high);
    }

    //*** Coalesce data & return ***//
    xdtData.insert(xdtData.end(), headerData.begin(), headerData.end());
    xdtData.insert(xdtData.end(), directoryData.begin(), directoryData.end());
    xdtData.insert(xdtData.end(), blobData.begin(), blobData.end());

    return xdtData;
}

bool xdt::Table::Deserialise(const std::vector<uint8_t> &data) {
    if(data.empty()) {
        errorStatus = "Empty data vector.";
        return false;
    }

    //*** Section byte vectors ***//
    const size_t headerSize = 10;

    auto headerData = std::vector<uint8_t>(data.begin(), data.begin()+headerSize);
    auto directoryData = std::vector<uint8_t>();
    auto blobData = std::vector<uint8_t>();

    xdt::Table tempTable;
    std::vector<std::pair<std::string, size_t>> blobItems;


    //*** Header ***//
    uint64_t hdr_magic =
        ((uint64_t)(headerData[0]) << 24) +
        ((uint64_t)(headerData[1]) << 16) +
        ((uint64_t)(headerData[2]) << 8) +
        ((uint64_t)(headerData[3]) << 0);

    if(hdr_magic != XDT_MAGIC) {
        errorStatus = "File not marked as XDT.";
        return false;
    }

    uint16_t hdr_version =
        ((uint64_t)(headerData[4]) << 0) +
        ((uint64_t)(headerData[5]) << 8);

    uint16_t hdr_flags =
        ((uint64_t)(headerData[6]) << 0) +
        ((uint64_t)(headerData[7]) << 8);

    uint16_t hdr_itemCount =
        ((uint64_t)(headerData[8]) << 0) +
        ((uint64_t)(headerData[9]) << 8);

    tempTable.headerInfo = HeaderInfo {
        hdr_version,
        HeaderFlags {
            (uint8_t)((hdr_flags & 0x00FF) >> 0),
            (uint8_t)((hdr_flags & 0xFF00) >> 8)
        }
    };

    //*** Items ***//
    size_t currentItem = 0;

    size_t currentOffset = headerSize + directoryData.size();

    while(currentItem < hdr_itemCount) {
        if(currentOffset > data.size()) {
            errorStatus = "Reached EOF while reading directory.";
            return false;
        }

        xdt::Item tempItem;

        // Get name
        uint8_t nameSize = data[currentOffset];
        currentOffset++;

        auto itemName = std::string(
            data.begin() + currentOffset,
            data.begin() + currentOffset + nameSize
        );
        currentOffset += nameSize;

        // Get type
        ItemType itemType = (ItemType)data[currentOffset];
        currentOffset++;

        // Get value
        std::vector<uint8_t> itemData = {};

        bool isBlob = (std::find(BLOBTypes.begin(), BLOBTypes.end(), itemType) != BLOBTypes.end());
        if(!isBlob) {
            size_t dataWidth = 0;
            switch(itemType) {
                case ItemType::Byte      : dataWidth = 1; break;
                case ItemType::Bool      : dataWidth = 1; break;
                case ItemType::Int16     : dataWidth = 2; break;
                case ItemType::Uint16    : dataWidth = 2; break;
                case ItemType::Int32     : dataWidth = 4; break;
                case ItemType::Uint32    : dataWidth = 4; break;
                case ItemType::Float     : dataWidth = 4; break;
                case ItemType::Timestamp : dataWidth = 4; break;
                default                  : dataWidth = 0; break;
            }

            itemData.insert(
                itemData.end(),
                data.begin() + currentOffset,
                data.begin() + currentOffset + dataWidth
            );
        }else {
            // Defer BLOB loading
            itemData.insert(
                itemData.end(),
                data.begin() + currentOffset,
                data.begin() + currentOffset + 4
            );

            uint32_t blobSize = *reinterpret_cast<uint32_t*>(itemData.data());

            itemData.clear();
            blobItems.push_back(std::make_pair(itemName, blobSize));
        }

        currentOffset += 4;

        // Get flags
        ItemFlags itemFlags;
        currentOffset += 2;

        // Submit item
        tempItem = Item {
            itemType,
            itemFlags,
            itemData
        };

        tempTable.directory.push_back(std::make_pair(itemName, tempItem));

        currentItem++;
    }


    //*** BLOB Data ***//
    for(auto &[blobName, blobSize] : blobItems) {
        if(currentOffset > data.size()) {
            errorStatus = "Reached EOF while reading BLOB data.";
            return false;
        }

        xdt::Item *item = tempTable.GetItem(blobName);

        if(item == nullptr) {
            errorStatus = "Unknown error occured.";
            return false;
        }

        item->data.insert(
            item->data.begin(),
            data.begin() + currentOffset,
            data.begin() + currentOffset + blobSize
        );

        // Decompress if necesarry
        if(XDT_GET_ITEM_COMPRESION(item->flags) == 0b01) {
            item->data = DecompressRLE(item->data);
        }

        currentOffset += blobSize;
    }

    //*** Finalise ***//
    headerInfo = tempTable.headerInfo;
    directory = tempTable.directory;

    return true;
}

// File IO
void xdt::Table::Save(const std::string &filename) {
    auto outBytes = Serialise();

    std::ofstream f(filename, std::ios::binary);
    for(auto b : outBytes) { f << b; }

    f.close();
}

bool xdt::Table::Load(const std::string &filename) {
    std::ifstream f("out.xdt", std::ios::binary);

    auto inBytes = std::vector<uint8_t>(
        std::istreambuf_iterator<char>(f),
        std::istreambuf_iterator<char>()
    );

    f.close();

    return Deserialise(inBytes);
}

// Constructors
xdt::Table::Table(const std::vector<uint8_t> &data) {
    Deserialise(data);
}

xdt::Table::Table(const std::string &filename) {
    Load(filename);
}

xdt::Table::Table(HeaderInfo header) {
    this->headerInfo = header;
}

xdt::Table::Table() : Table(
    HeaderInfo {
        0x0010,
        {0x00, 0x00}
    }
) {}