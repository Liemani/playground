#ifndef HEX_DUMP_H
#define HEX_DUMP_H

#include <cstddef>  // std::size_t

void hex_dump(const unsigned char* address, std::size_t length);

#endif  // HEX_DUMP_H
