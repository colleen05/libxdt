/**
 * @file libxdt.hpp
 * @brief LibXDT's single header file.
 * @details Contains all declarations for using LibXDT.
 */

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#define XDT_MAGIC 0x00584454 //!< 4-byte sequence used at the beginning of a file to declare it is XDT-formatted.

namespace xdt {
    /*! @brief Bitfield for header flags
     *  @details Contains information about how provided XDT-formatted data
     *  may be encoded. The high-byte may be used for non-standard encodings.
     */
    struct HeaderFlags {
    };

    /*! @brief Container for header information
     *  @details Contains header information as provided in the XDT
     *  specification, such as encoding version and flags.
     *  @note
     *  - Does not contain the **magic** field as defined in the
     *  specification, as it is a static value, and will automatically be
     *  prepended to serialised data by the Table class.
     * 
     *  - Does not contain the **item count** field as declared in the
     *  specification, as it can be obtained from the directory member in the
     *  Table class, and will automatically be written to serialised data.
     */
    struct HeaderInfo {
        uint16_t version;   //!< Version field which states what standard, or non-standard encoding version the XDT-formatted data uses.
        HeaderFlags flags;  //!< Bitfield for flags stored in the header.
    };

    /*! @brief Item type enumeration, values from specification.
     *  @details IDs for various types of data which an item can contain,
     *  identical to those which are defined in the XDT specification. It is
     *  used by LibXDT for decerning how to serialise / deserialise data
     *  within XDT files / the Table class.
     */
    enum class ItemType {
        Byte            = 0x00, //!< `0x00`: Byte (unsigned char)
        Bool            = 0x01, //!< `0x01`: Boolean (bool)
        Int16           = 0x02, //!< `0x02`: Signed 16-bit integer (int16_t)
        Uint16          = 0x03, //!< `0x03`: Unsigned 16-bit integer (uint16_t)
        Int32           = 0x04, //!< `0x04`: Signed 32-bit integer (int16_t)
        Uint32          = 0x05, //!< `0x05`: Unsigned 32-bit integer (uint16_t)
        Int64           = 0x06, //!< `0x06`: Signed 64-bit integer (int16_t)
        Uint64          = 0x07, //!< `0x07`: Unsigned 64-bit integer (uint16-t)
        Float           = 0x08, //!< `0x08`: Floating-point number (float)
        Double          = 0x09, //!< `0x09`: Double-precision floating-point number (double)
        Timestamp       = 0x0A, //!< `0x0A`: 32-bit UNIX timestamp (int32_t / std::chrono::time_point)
        LongTimestamp   = 0x0B, //!< `0x0B`: 64-bit UNIX timestamp (int64_t / std::chrono::time_point)
        ASCIIString     = 0x0C, //!< `0x0C`: ASCII-encoded string (char[] / std::string)
        UTF8String      = 0x0D, //!< `0x0D`: UTF8-encoded string (std::wstring)
        File            = 0x0E, //!< `0x0E`: File data (uint8_t[] / std::vector<uint8_t>)
        Raw             = 0x0F  //!< `0x0F`: Raw binary data (uint8_t[] / std::vector<uint8_t>)
    };

    /*! @brief Per-item bitfield for directory entries
     *  @details Contains information about how an individual item is encoded,
     *  regardless of what type of data is stored (such as compression). The
     *  high-byte may be used for non-standard encodigns.
     */
    struct ItemFlags {
        //! Information about which compression scheme to use, as defined in the specification.
        /*!
         * Compression schemes are as followed, ordered by effeciency/time:
         * Code     | Compression Scheme
         * ---------|-------------------
         * ``0b00`` | No compression
         * ``0b01`` | Run-length encoding (RLE)
         * ``0b10`` | LZ77
         * ``0b11`` | DEFLATE
         */
        uint8_t compression_info : 2;

    };

    /*! @brief Per-item container for item information
     *  @details Contains information about an individual item within the
     *  directory of XDT-formatted data, such as the item's data type,
     *  its flags, and a vector to the data itself.
     *  @note Does not contain the **size/value** field as declared in the
     *  specification, but instead contains a **data** member which will
     *  automatically be correctly serialised by the Table class.
     */
    struct Item {
        ItemType    type;           //!< What data-type the individual item contains.
        ItemFlags   flags;          //!< Flags containing additional information.
        std::vector<uint8_t> data;  //!< Data as bytes.
    };

    /*! @brief Class for managing XDT-data.
     *  @details Provides functionality for encoding/decoding to and from
     *  XDT-formatted data. All table data is stored such that they can be
     *  read and modified with C++.
     */
    class Table {
        public:
            HeaderInfo headerInfo; //!< Header information such as version, flags, and the number of table items.
            std::unordered_map<std::string, Item> directory; //!< The container for all items, indexed by name.

            std::vector<uint8_t> Serialise(); //!< Returns an XDT-formatted byte array of the table.
            bool Deserialise(std::vector<uint8_t> data); //!< Loads data from an XDT-formatted byte array.

            Table();
    };
}