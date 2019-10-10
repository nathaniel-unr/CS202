#ifndef PROJ4_H_
#define PROJ4_H_

#include <fstream>
#include <iostream>

// Can't make constants.h
const int CAR_NUM = 5;
const int SENSOR_NUM = 3;
const int STR_MAX = 256;

// counts characters in str array until a NULL-character '\0' is found, then it
// returns that number excluding the '\0' one the return type size_t represents
// an unsigned integral number large enough to contain the maximum possible
// number of a storage size that can appear on a target architecture
size_t myStringLength(const char *str);

// returns 0 when the C-strings match, i.e. their characters are equal
// one-by-one until a NULL-character '\0' is found in both strings and at the
// same position as well returns a value <=-1 if the first character that does
// not match has a lower value in str1 than in str2 returns a value >=1 if the
// first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char *str1, const char *str2);

// copies characters from source to destination array until a NULL-character
// '\0' is found in source, then it NULL-terminates destination too returns a
// pointer to the destination array
char *myStringCopy(char *destination, const char *source);

// appends the content of source to the destination array
// this means that the NULL-terminator of destination is overwritten by the
// first character of source and a NULL-character '\0' is appended at the end of
// the concatenated Cstring in destination returns a pointer to the destination
// array
char *myStringCat(char *destination, const char *source);

/// Trims the start of a string and copies to a buffer. Retunrs true if string
/// was trimmed.
bool trimStart(const char *str, char *dest, char c);

/// Trims the end of a string and copies to a buffer. Retunrs true if string was
/// trimmed.
bool trimEnd(const char *str, char *dest, char c);

/*
Agency a = Agency::readAllData(file);
copy((unsigned char *)&m_agency, (unsigned char *)&a, sizeof(Agency));

void copy(unsigned char *dest, const unsigned char *src, int len) {
  for (int i = 0; i != len; i++) {
    *(dest + i) = *(src + i);
  }
}
*/

#endif