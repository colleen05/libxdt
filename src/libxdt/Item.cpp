#include <libxdt.hpp>

#pragma region xdt::Item Getters

uint8_t xdt::Item::GetByte() {
    switch(type) {
        case ItemType::Byte:            return (data.size() == 1) ? data[0] : 0x00; break;
        case ItemType::Bool:            return GetInt16();  break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        default: return 0x00; break;
    }

    return 0x00;
}

bool xdt::Item::GetBool() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return (data.size() == 1) ? data[0] : false; break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count() > 0; break;
        case ItemType::LongTimestamp:   return GetTimestamp().count() > 0; break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        case ItemType::File:            return !data.empty(); break;
        case ItemType::Raw:             return !data.empty(); break;
        default: return false; break;
    }

    return false;
}

int16_t xdt::Item::GetInt16() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return (data.size() == 2) ? (*reinterpret_cast<int16_t*>(data.data())) : 0; break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        default: return 0; break;
    }

    return 0;
}

uint16_t xdt::Item::GetUint16() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return (data.size() == 2) ? (*reinterpret_cast<uint16_t*>(data.data())) : 0; break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        default: return 0; break;
    }

    return 0;
}

int32_t xdt::Item::GetInt32() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return (data.size() == 4) ? (*reinterpret_cast<int32_t*>(data.data())) : 0; break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        default: return 0; break;
    }

    return 0;
}

uint32_t xdt::Item::GetUint32() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return (data.size() == 4) ? (*reinterpret_cast<uint32_t*>(data.data())) : 0; break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        default: return 0; break;
    }

    return 0;
}

int64_t xdt::Item::GetInt64() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return (data.size() == 8) ? (*reinterpret_cast<int64_t*>(data.data())) : 0; break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        default: return 0; break;
    }

    return 0;
}

uint64_t xdt::Item::GetUint64() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return (data.size() == 8) ? (*reinterpret_cast<uint64_t*>(data.data())) : 0; break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atoi(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atoi(GetString().c_str()); break;
        default: return 0; break;
    }

    return 0;
}

float xdt::Item::GetFloat() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return (data.size() == 4) ? (*reinterpret_cast<float*>(data.data())) : 0.0f; break;
        case ItemType::Double:          return GetDouble(); break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atof(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atof(GetString().c_str()); break;
        default: return 0.0f; break;
    }

    return 0.0f;
}

double xdt::Item::GetDouble() {
    switch(type) {
        case ItemType::Byte:            return GetByte();   break;
        case ItemType::Bool:            return GetBool();   break;
        case ItemType::Int16:           return GetInt16();  break;
        case ItemType::Uint16:          return GetUint16(); break;
        case ItemType::Int32:           return GetInt32();  break;
        case ItemType::Uint32:          return GetUint32(); break;
        case ItemType::Int64:           return GetInt64();  break;
        case ItemType::Uint64:          return GetUint64(); break;
        case ItemType::Float:           return GetFloat();  break;
        case ItemType::Double:          return (data.size() == 8) ? (*reinterpret_cast<double*>(data.data())) : 0.0; break;
        case ItemType::Timestamp:       return GetTimestamp().count(); break;
        case ItemType::LongTimestamp:   return GetTimestamp().count(); break;
        case ItemType::ASCIIString:     return std::atof(GetString().c_str()); break;
        case ItemType::UTF8String:      return std::atof(GetString().c_str()); break;
        default: return 0.0; break;
    }

    return 0.0;
}

std::chrono::seconds xdt::Item::GetTimestamp() {
    switch(type) {
        case ItemType::Timestamp:       return std::chrono::seconds((data.size() == 4) ? (*reinterpret_cast<int32_t*>(data.data())) : 0); break;
        case ItemType::LongTimestamp:   return std::chrono::seconds((data.size() == 8) ? (*reinterpret_cast<int64_t*>(data.data())) : 0); break;
        default: return std::chrono::seconds(0); break;
    }

    return std::chrono::seconds(0);
}

std::string xdt::Item::GetString(bool asHex) {
    std::stringstream ss;

    if(asHex) ss << "0x" << std::hex << std::setfill('0');

    switch(type) {
        case ItemType::Byte:        if(asHex) { ss << std::setw(2);  } ss << (int)GetByte(); break;
        case ItemType::Bool:        return GetByte() ? "true" : "false";                     break;
        case ItemType::Int16:       if(asHex) { ss << std::setw(4);  } ss << GetInt16();     break;
        case ItemType::Uint16:      if(asHex) { ss << std::setw(4);  } ss << GetUint16();    break;
        case ItemType::Int32:       if(asHex) { ss << std::setw(8);  } ss << GetInt32();     break;
        case ItemType::Uint32:      if(asHex) { ss << std::setw(8);  } ss << GetUint32();    break;
        case ItemType::Int64:       if(asHex) { ss << std::setw(16); } ss << GetInt64();     break;
        case ItemType::Uint64:      if(asHex) { ss << std::setw(16); } ss << GetUint64();    break;
        case ItemType::Float:       if(asHex) { ss << std::setw(8);  } ss << GetFloat();     break;
        case ItemType::Double:      if(asHex) { ss << std::setw(16); } ss << GetDouble();    break;
        case ItemType::Timestamp:
            return std::to_string(GetTimestamp().count());
            break;
        case ItemType::LongTimestamp:
            return std::to_string(GetTimestamp().count());
            break;
        case ItemType::ASCIIString:
        case ItemType::UTF8String:
            if(data.empty()) return "";
            return std::string(data.begin(), data.end());
            break;

        default: return "";
    }

    return ss.str();
}

std::vector<uint8_t> xdt::Item::GetBytes() {
    return data;
}

#pragma endregion

#pragma region xdt::Item Setters

void xdt::Item::SetByte(uint8_t value, bool overwriteType) {
    if(overwriteType) type = ItemType::Byte;
    if(type != ItemType::Byte) return;

    data.clear();
    data.push_back(value);
}


void xdt::Item::SetBool(bool value, bool overwriteType) {
    if(overwriteType) type = ItemType::Bool;
    if(type != ItemType::Bool) return;

    data.clear();
    data.push_back(value ? 0x01 : 0x00);
}

void xdt::Item::SetInt16(int16_t value, bool overwriteType) {
    if(overwriteType) type = ItemType::Int16;
    if(type != ItemType::Int16) return;

    data.clear();
    data.push_back((value & 0x00FF) >> 0);
    data.push_back((value & 0xFF00) >> 8);
}

void xdt::Item::SetUint16(uint16_t value, bool overwriteType) {
    if(overwriteType) type = ItemType::Uint16;
    if(type != ItemType::Uint16) return;

    data.clear();
    data.push_back((value & 0x00FF) >> 0);
    data.push_back((value & 0xFF00) >> 8);
}

void xdt::Item::SetInt32(int32_t value, bool overwriteType) {
    if(overwriteType) type = ItemType::Int32;
    if(type != ItemType::Int32) return;

    data.clear();
    data.push_back((value & 0x000000FF) >> 0);
    data.push_back((value & 0x0000FF00) >> 8);
    data.push_back((value & 0x00FF0000) >> 16);
    data.push_back((value & 0xFF000000) >> 24);
}

void xdt::Item::SetUint32(uint32_t value, bool overwriteType) {
    if(overwriteType) type = ItemType::Uint32;
    if(type != ItemType::Uint32) return;

    data.clear();
    data.push_back((value & 0x000000FF) >> 0);
    data.push_back((value & 0x0000FF00) >> 8);
    data.push_back((value & 0x00FF0000) >> 16);
    data.push_back((value & 0xFF000000) >> 24);
}

void xdt::Item::SetInt64(int64_t value, bool overwriteType) {
    if(overwriteType) type = ItemType::Int64;
    if(type != ItemType::Int64) return;

    data.clear();
    data.push_back((value & 0x00000000000000FF) >> 0);
    data.push_back((value & 0x000000000000FF00) >> 8);
    data.push_back((value & 0x0000000000FF0000) >> 16);
    data.push_back((value & 0x00000000FF000000) >> 24);
    data.push_back((value & 0x000000FF00000000) >> 32);
    data.push_back((value & 0x0000FF0000000000) >> 40);
    data.push_back((value & 0x00FF000000000000) >> 48);
    data.push_back((value & 0xFF00000000000000) >> 56);
}

void xdt::Item::SetUint64(uint64_t value, bool overwriteType) {
    if(overwriteType) type = ItemType::Uint64;
    if(type != ItemType::Uint64) return;

    data.clear();
    data.push_back((value & 0x00000000000000FF) >> 0);
    data.push_back((value & 0x000000000000FF00) >> 8);
    data.push_back((value & 0x0000000000FF0000) >> 16);
    data.push_back((value & 0x00000000FF000000) >> 24);
    data.push_back((value & 0x000000FF00000000) >> 32);
    data.push_back((value & 0x0000FF0000000000) >> 40);
    data.push_back((value & 0x00FF000000000000) >> 48);
    data.push_back((value & 0xFF00000000000000) >> 56);
}


void xdt::Item::SetFloat(float value, bool overwriteType) {
    if(overwriteType) type = ItemType::Float;
    if(type != ItemType::Float) return;

    uint32_t rawvalue = *reinterpret_cast<uint32_t*>(&value);

    data.clear();
    data.push_back((rawvalue & 0x000000FF) >> 0);
    data.push_back((rawvalue & 0x0000FF00) >> 8);
    data.push_back((rawvalue & 0x00FF0000) >> 16);
    data.push_back((rawvalue & 0xFF000000) >> 24);
}

void xdt::Item::SetDouble(double value, bool overwriteType) {
    if(overwriteType) type = ItemType::Double;
    if(type != ItemType::Double) return;

    uint64_t rawvalue = *reinterpret_cast<uint64_t*>(&value);

    data.clear();
    data.push_back((rawvalue & 0x00000000000000FF) >> 0);
    data.push_back((rawvalue & 0x000000000000FF00) >> 8);
    data.push_back((rawvalue & 0x0000000000FF0000) >> 16);
    data.push_back((rawvalue & 0x00000000FF000000) >> 24);
    data.push_back((rawvalue & 0x000000FF00000000) >> 32);
    data.push_back((rawvalue & 0x0000FF0000000000) >> 40);
    data.push_back((rawvalue & 0x00FF000000000000) >> 48);
    data.push_back((rawvalue & 0xFF00000000000000) >> 56);
}

void xdt::Item::SetTimestamp(std::chrono::seconds value, bool isLong, bool overwriteType) {
    if(overwriteType) type = isLong ? ItemType::LongTimestamp : ItemType::Timestamp;
    if(isLong) { if(type != ItemType::LongTimestamp) return; }
    else       { if(type != ItemType::Timestamp)     return; }

    data.clear();

    if(isLong) {
        int64_t secs = value.count();
        uint64_t rawvalue = *reinterpret_cast<uint64_t*>(&secs);

        data.push_back((rawvalue & 0x00000000000000FF) >> 0);
        data.push_back((rawvalue & 0x000000000000FF00) >> 8);
        data.push_back((rawvalue & 0x0000000000FF0000) >> 16);
        data.push_back((rawvalue & 0x00000000FF000000) >> 24);
        data.push_back((rawvalue & 0x000000FF00000000) >> 32);
        data.push_back((rawvalue & 0x0000FF0000000000) >> 40);
        data.push_back((rawvalue & 0x00FF000000000000) >> 48);
        data.push_back((rawvalue & 0xFF00000000000000) >> 56);
    }else {
        int32_t secs = value.count();
        uint32_t rawvalue = *reinterpret_cast<uint32_t*>(&secs);

        data.push_back((rawvalue & 0x000000FF) >> 0);
        data.push_back((rawvalue & 0x0000FF00) >> 8);
        data.push_back((rawvalue & 0x00FF0000) >> 16);
        data.push_back((rawvalue & 0xFF000000) >> 24);
    }
}

void xdt::Item::SetString(std::string value, bool isUTF8, bool overwriteType) {
    if(overwriteType) type = isUTF8 ? ItemType::UTF8String : ItemType::ASCIIString;
    if(isUTF8) { if(type != ItemType::UTF8String)  return; }
    else       { if(type != ItemType::ASCIIString) return; }

    data.clear();
    for(auto c : value) {
        data.push_back(c);
    }
}

void xdt::Item::SetBytes(std::vector<uint8_t> value, bool isFileData, bool overwriteType) {
    if(overwriteType) type = isFileData ? ItemType::File : ItemType::Raw;
    if(isFileData)  { if(type != ItemType::File)  return; }
    else            { if(type != ItemType::Raw)   return; }

    data.clear();
    for(auto c : value) {
        data.push_back(c);
    }
}

#pragma endregion

std::string xdt::GetTypeString(xdt::ItemType type) {
    switch(type) {
        case ItemType::Byte         : return "Byte";            break;
        case ItemType::Bool         : return "Bool";            break;
        case ItemType::Int16        : return "Int16";           break;
        case ItemType::Uint16       : return "Uint16";          break;
        case ItemType::Int32        : return "Int32";           break;
        case ItemType::Uint32       : return "Uint32";          break;
        case ItemType::Int64        : return "Int64";           break;
        case ItemType::Uint64       : return "Uint64";          break;
        case ItemType::Float        : return "Float";           break;
        case ItemType::Double       : return "Double";          break;
        case ItemType::Timestamp    : return "Timestamp";       break;
        case ItemType::LongTimestamp: return "LongTimestamp";   break;
        case ItemType::ASCIIString  : return "ASCIIString";     break;
        case ItemType::UTF8String   : return "UTF8String";      break;
        case ItemType::File         : return "File";            break;
        case ItemType::Raw          : return "Raw";             break;
        default:
            return std::to_string((int)type);
            break;
    }
}