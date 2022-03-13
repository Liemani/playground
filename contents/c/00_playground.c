#include <stdio.h>

#define GROUND000
#ifdef GROUND000
//	display bits of float value
//	exponent bit가 전부 1이고 mantissa bit가 전부 0이면 inf이다.
//	exponent bit가 전부 1이고 mantissa bit 중 1이 존재하면 nan이다.
//	  00000000 00000000 00000000 01001011
//	+ 00000000 00000000 10000000 00111111
//	= 00000001 00000000 00000000 01001011
//	2 ^ 23 + 2 ^ 0 은 더하기가 된다.
//	2 ^ 24 + 2 ^ 0 은 더해지지 않는다.
//	struct의 bit field member는 byte를 순서대로 차지하고 bit는 거꾸로 차지한다.
#include <math.h>

#define BIG_ENDIAN		0
#define LITTLE_ENDIAN	1
#define ENDIAN	LITTLE_ENDIAN

#ifndef STRING
// #define STRING	" 11111111 11111111 01111111 01111111"
#define STRING	" 00000001 00000000 00000000 00000000"
// #define STRING	" 00000000 00000000 10000000 00000000"
// #define STRING	" 00000000 00000000 00000000 01001011"
// #define STRING	" 00000000 00000000 00000000 01001011"
#endif

#ifndef NUMBER
#define NUMBER 1
#endif

void beforeStart(void);

void setFloatToStr(float* number);

void strToBit(char str[36], char bits[32]);

void bitToFloat(char bits[32], float* number);
void bitToChar(char bits[8], char* ch);

void floatToBit(float data, char bits[32]);
void charToBit(char ch, char bits[8]);

void describeBit(char bits[32]);

typedef union ClearFloat{
	char raw[4];
	float data;
} ClearFloat;

typedef union ieee754_float {
	float floatNumber;
	struct {
		unsigned int mantissa:23;
		unsigned int exponent:8;
		unsigned int negative:1;
	} ieee;
} ieee754_float;

int main(void) {
	ieee754_float ieee;
	float number = NUMBER;
	char bits[32];

	beforeStart();

	ieee.ieee.negative = 1;
	ieee.ieee.exponent = 2;
	ieee.ieee.mantissa = 2;
	floatToBit(ieee.floatNumber, bits);
	describeBit(bits);

	setFloatToStr(&number);
	while (1) {
		floatToBit(number, bits);

		describeBit(bits);
		printf("number: %0.20f\n", number);
		printf("number: %0.20e\n", number);
		break;
		++number;
	}

	return 0;
}

void beforeStart(void) {
	printf("sizeof(ieee754_float): %ld\n", sizeof(ieee754_float));
}

void setFloatToStr(float* number) {
	char bits[33];

	strToBit(STRING, bits);
	bitToFloat(bits, number);
}

void strToBit(char str[36], char bits[32]) {
	for(int i = 0, j = 0; i < 32; ++i, ++j) {
		if (i % 8 == 0)
			++j;
		bits[i] = str[j];
	}
}

void bitToFloat(char bits[32], float* number) {
	ClearFloat temp;

	temp.data = 0;
	for (int i = 0; i < 4; ++i) {
		bitToChar(&bits[8 * i], &temp.raw[i]);
	}
	*number = temp.data;
}

void bitToChar(char bits[8], char* ch) {
	char temp;

	temp = 0;
	for (int i = 0; i < 8; ++i) {
		temp |= (bits[i] - '0') << (7 - i);
	}
	*ch = temp;
}

void floatToBit(float number, char bits[32]) {
	ClearFloat data;

	data.data = number;
	for (int i = 0; i < 4; ++i) {
		charToBit(data.raw[i], &bits[8 * i]);
	}
}

void charToBit(char ch, char bits[8]) {
	for (int i = 0; i < 8; ++i) {
		bits[i] = '0' + (ch >> (8 - i - 1) & 0x1);
	}
}

void describeBit(char bits[32]) {
	for (int i = 0; i < 32; ++i) {
		if (i % 8 == 0)
			putchar(' ');
		putchar(bits[i]);
	}
	putchar('\n');
}
#endif
