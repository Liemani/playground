// goal : 00000000 : cffa edfe 0c00 0001 0000 0000 0200 0000  ................
#include "hex_dump.h"

#include <iostream>
#include <algorithm>  // std::min()
#include <cstdint>  // std::uintptr_t
#include <iomanip>  // std::setw()
#include <cstdio>   // snprintf()
#include <cstring>  // memset()
#include <cstddef>  // std::size_t

const char* printable_ascii = "................................ !\"#$%&\'()*+,-./0123456789:;<=>\?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~.................................................................................................................................";

// Line
class Line
{
public :
  static const std::size_t content_size = 76;

private :
  char content[content_size];
  const char new_line;
  const char terminator;

public :
  Line();
  char& operator[](std::size_t offset);
  char* operator&();
};

Line::Line()
  : new_line('\n')
  , terminator('\0')
{
}

char& Line::operator[](std::size_t offset)
{
  return this->content[offset];
}

char* Line::operator&()
{
  return (char*)this;
}

// function prototype
void hex_dump_line(Line& line, const unsigned char* address, std::size_t length);
void decimal_to_hexadecimal(char* destination, uint64_t decimal, std::size_t decimal_size);

// hex_dump()
void hex_dump(const unsigned char* address, std::size_t length)
{
  Line line;

  while (0 < length)
  {
    const std::size_t line_length = std::min((std::size_t)16, length);

    hex_dump_line(line, address, line_length);
    std::cout << &line;

    address += line_length;
    length -= line_length;
  }
}

// hex_dump_line()
// must
// length [1,16]
void hex_dump_line(Line& line, const unsigned char* address, std::size_t length)
{
  memset(&line, ' ', Line::content_size);

  decimal_to_hexadecimal(&line, (uint64_t)address, 8);
  line[16] = ' ';
  line[17] = ':';

  for (int i = 0; i < length; ++i)
  {
    const int destination_offset = 19 + 5 * (i / 2) + (i % 2) * 2;
    const int source_offset = 2 * (i / 2) + (i % 2);
    decimal_to_hexadecimal(&line + destination_offset, *(address + source_offset), 1);
    line[destination_offset + 2] = ' ';

    line[60 + i] = printable_ascii[*(address + i)];
  }

  if (length != 16)
  {
    line[60 + length] = '\n';
    line[60 + length + 1] = '\0';
  }
}

// decimal_to_hexadecimal
// must
// destination != null
// destination size [decimal_size * 2 + 1,)
// decimal_size [0,4]
uint64_t decimal_size_mask[9] = {
  0x0000000000000000,
  0x00000000000000ff,
  0x000000000000ffff,
  0x0000000000ffffff,
  0x00000000ffffffff,
  0x000000ffffffffff,
  0x0000ffffffffffff,
  0x00ffffffffffffff,
  0xffffffffffffffff,
};

void decimal_to_hexadecimal(char* destination, uint64_t decimal, std::size_t decimal_size)
{
  decimal &= decimal_size_mask[decimal_size];
  const std::size_t destination_length = decimal_size * 2;

  // goal : %08llx(%0nllx)
  // goal : %016llx(%0nnllx)
  char format_string[32];
  snprintf(format_string, 32, "%%0%zullx", destination_length);
  snprintf(destination, destination_length + 1, format_string, decimal);
}
