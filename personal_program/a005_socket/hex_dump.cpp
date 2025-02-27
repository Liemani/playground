// goal : 00000000 : cffa edfe 0c00 0001 0000 0000 0200 0000  ................
#include "hex_dump.h"

#include <iostream>
#include <algorithm>  // std::min()
#include <cstdint>  // std::uintptr_t
#include <iomanip>  // std::setw()
#include <cstdio>   // snprintf()
#include <cstring>  // memset()
#include <cstddef>  // std::size_t

void hex_dump_line(const unsigned char* address, std::size_t length);
void decimal_to_hexadecimal(char* destination, unsigned int decimal, std::size_t decimal_size);

const char* printable_ascii = "................................ !\"#$%&\'()*+,-./0123456789:;<=>\?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~.................................................................................................................................";

class Line {
private :
  char content[68];
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

Line line;

// hex_dump
void hex_dump(const unsigned char* address, std::size_t length)
{
  while (true)
  {
    hex_dump_line(address, length);
    std::cout << &line;

    if (length <= 16)
    {
      break;
    }

    address += 16;
    length -= 16;
  }
}

// hex_dump_line
// length != 0
// if length > 16, process 16 length
void hex_dump_line(const unsigned char* address, std::size_t length)
{
  if (length == 0)
  {
    return;
  }

  length = std::min((std::size_t)16, length);

  memset(&line, ' ', 68);

  decimal_to_hexadecimal(&line, (unsigned int)(std::uintptr_t)address, 4);
  line[9] = ':';

  for (int i = 0; i < length; ++i)
  {
    decimal_to_hexadecimal(&line + 11 + 5 * (i / 2) + (i % 2) * 2, *(unsigned short*)(address + 2 * (i / 2) + (i % 2)), 1);

    line[52 + i] = printable_ascii[*(address + i)];

    if (length <= i)
    {
      break;
    }
  }
}

// decimal_to_hexadecimal
// suppose destination != null
// suppose decimal_size (0,4]
// suppose destination size [decimal_size * 2 + 1,)
unsigned int decimal_size_mask[5] = { 0x00000000, 0x000000ff, 0x0000ffff, 0x00ffffff, 0xffffffff };

void decimal_to_hexadecimal(char* destination, unsigned int decimal, std::size_t decimal_size)
{
  decimal &= decimal_size_mask[decimal_size];
  const std::size_t destination_length = decimal_size * 2;

  // goal : %08x(%0nx)
  char format_string[5] = "%0nx";
  format_string[2] = '0' + destination_length;
  snprintf(destination, destination_length + 1, format_string, decimal);
  destination[destination_length] = ' ';
}
