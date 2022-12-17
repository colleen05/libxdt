<p align="center">
  <img src="img/logo.png">
  <br>
  <a href="#about">About </a>•
  <a href="#features">Features </a>•
  <a href="#supported-types">Types </a>•
  <a href="#example-code">Examples </a>•
  <a href="#building">Building </a>•
  <a href="#format">Format</a>
</p>


# About
The **LibXDT** C++ library provides functionality for reading, writing, and modifying XDT (e**X**tensive **D**ata **T**able) files. XDT is the successor to the [BSM](https://github.com/colleen05/bsmlib) format.

# Features
XDT compiles multiple data objects and values (collectively, "items") into a sort of "table" or "dictionary", where each item is given a name (up to **256 characters**). XDT supports up to **65536 items**. Some items are considered **BLOBs**, which stands for Binary Large OBjects, which are allowed to be up to **4GB in size**. Simple items under 4 bytes in data-length get their values stored next to them in the directory, whereas BLOBs and larger values (such as long timestamps and doubles) get their value stored as a BLOB.

The XDT format **is highly extendable**, with plenty of room for custom, domain-specific alterations of the format to use for their own purpose. XDT can support up to **128 custom types**, and there is room in both the header *and* directory entries for custom fields.

## Supported types
XDT supports **16 standard types**, summarised as follows:
* Byte (unsigned)
* Boolean (`bool`)
* Unsigned integers (16-bit, 32-bit, and 64-bit)
* Signed integers (16-bit, 32-bit, and 64-bit)
* Floating-point numbers (single-precision floats, and double-precision doubles)
* Timestamps (both 32-bit and 64-bit)
* Strings (both ACII and UTF-8)
* Raw binary (with distinction between file-data and just raw binary)

# Example code
Here is some example code to get you started with using the LibXDT library.
**NOTE:** There exists a `Demo.cpp` file in this repository, which demonstrates usage of this library in greater detail.

## 1. Writing values to a file
```cpp
#include <libxdt.hpp>

int main() {
    xdt::Table myTable;

    outTable.SetByte      ("my_byte",           0x48,       true);
    outTable.SetBool      ("my_bool",           true,       true);
    outTable.SetInt16     ("my_int16",          -1234,      true);
    outTable.SetUint16    ("my_uint16",         6502,       true);
    outTable.SetInt32     ("my_int32",          -314159,    true);
    outTable.SetUint32    ("my_uint32",         12345,      true);
    outTable.SetInt64     ("my_int64",          -987654321, true);
    outTable.SetUint64    ("my_uint64",         11235813,   true);
    outTable.SetFloat     ("my_float",          3.14159f,   true);
    outTable.SetDouble    ("my_double",         -0.012345,  true);
    outTable.SetTimestamp ("my_timestamp",      std::chrono::seconds(1670971965),   false,  true);
    outTable.SetTimestamp ("my_long_timestamp", std::chrono::seconds(1670971965),   true,   true);
    outTable.SetString    ("my_string",         "Hello, world!",                    false,  true);
    outTable.SetString    ("my_utf8_string",    "Cats🐈 are cool! 💖",              true,   true);
    outTable.SetBytes     ("my_file_data",      std::vector<uint8_t>(fileString.begin(), fileString.end()), true, true);
    outTable.SetBytes     ("my_raw_data",       {0x12, 0x34, 0x56, 0x78, 0x9A}, false, true);

    myTable.Save("myTable.xdt");

    return 0;
}
```
## 2. Reading and iterating values from a file
```cpp
#include <libxdt.hpp>

int main() {
    xdt::Table myTable("myTable.xdt");

    for(auto &[name, item] : myTable.directory) {
        std::cout << xdt::GetTypeName(item.type) << ": " << item.name << " = " << item.GetString() << std::endl;
    }

    return 0;
}
```

# Building & Using
## Linux

## Windows
I haven't made an official

# Format
XDT is a binary-formatted format. I've made two diagrams which briefly explain the specification.
![Diagram Page 1](/img/Diagram_Page1.png)
![Diagram Page 2](/img/Diagram_Page2.png)