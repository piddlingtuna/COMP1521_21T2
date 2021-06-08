#include <stdint.h>

             // range of values for type
             //             minimum               maximum
int8_t   i1; //                 -128                  127
uint8_t  i2; //                    0                  255
int16_t  i3; //               -32768                32767
uint16_t i4; //                    0                65535
int32_t  i5; //          -2147483648           2147483647
uint32_t i6; //                    0           4294967295
int64_t  i7; // -9223372036854775808  9223372036854775807
uint64_t i8; //                    0 18446744073709551615

/*
char is either signed or unsigned.
int is at least 4 bytes (might be longer).
*/


// int8_t, uint8_t - or 2^8 values
// int16_t, uint16_t - 2^16 values

#define EOF -1 // on most, not all, systems
// char - Actual type can be either signed or unsigned.
