<img src="img/logo.png" align="center">

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


# Format
XDT is a binary-formatted format. I've made two diagrams which briefly explain the specification.
![Diagram Page 1](/img/Diagram_Page1.png)
![Diagram Page 2](/img/Diagram_Page2.png)