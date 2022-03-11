#include <stdio.h>

#define GROUND000
#ifdef GROUND000
//	display bits of float value
//	exponent bit가 전부 1이고 mantissa bit가 전부 0이면 inf이다.
//	exponent bit가 전부 1이고 mantissa bit 중 1이 존재하면 nan이다.
#include <math.h>

#define BIG_ENDIAN		0
#define LITTLE_ENDIAN	1
#define ENDIAN	LITTLE_ENDIAN

#ifndef STRING
// #define STRING	" 01111111 01111111 11111111 11111111"
// #define STRING	" 00000000 00000000 00000000 00000001"
// #define STRING	" 00000000 10000000 00000000 00000000"
#define STRING	" 00111111 10000000 00000000 00000001"
#endif

#ifndef NUMBER
#define NUMBER 1
#endif

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

int main(void) {
	char bits[33];
	float number = NUMBER;

	setFloatToStr(&number);
	floatToBit(number, bits);
	bits[32] = '\0';

	describeBit(bits);
	printf("number: %0.20f\n", number);
	printf("number: %0.20e\n", number);

	return 0;
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
	if (ENDIAN == BIG_ENDIAN) {
		for (int i = 0; i < 4; ++i) {
			bitToChar(&bits[8 * i], &temp.raw[i]);
		}
	}
	else {
		for (int i = 0; i < 4; ++i) {
			bitToChar(&bits[8 * i], &temp.raw[3 - i]);
		}
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
	if (ENDIAN == BIG_ENDIAN) {
		for (int i = 0; i < 4; ++i) {
			charToBit(data.raw[i], &bits[8 * i]);
		}
	}
	else {
		for (int i = 0; i < 4; ++i) {
			charToBit(data.raw[3 - i], &bits[8 * i]);
		}
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
