// Base file

#ifndef BASE_H
#define BASE_H

#include <_types/_uint8_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_int64_t.h>
#include <sys/_types/_int8_t.h>

#if defined(__clang__)
#define COMPILER_CLANG 1
#elif defined(_MSC_VER)
#define COMPILER_MSC 1
#elif defined(__GNUC__)
#define COMPILER_GCC 1
#endif

#if defined(COMPILER_CLANG)
#define FILE_NAME __FILE_NAME__
#else
#define FILE_NAME __FILE__
#endif

////////////////////////////////
// Types
#include <stdint.h>
typedef int8_t I8;
typedef int16_t I16;
typedef int32_t I32;
typedef int64_t I64;
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef float F32;
typedef double F64;

////////////////////////////////
// Compound Types
// TODO: Don't know what to do here but like vectors

typedef struct TwoDimensionalVecI32 {
  I32 x;
  I32 y;
} TwoDimensionalVecI32;

typedef struct TwoDimensionalVecDouble {
  F32 x;
  F32 y;
} TwoDimensionalVecF32;

typedef struct TwoDimensionalVecF64 {
  F64 x;
  F64 y;
} TwoDimensionalVecF64;

////////////////////////////////
// Constants
// TODO: Come back to this (don't know what to add here now)

// const I16 MaxI16 = (I16)0xFFFF - (I16)1;

////////////////////////////////
// Symbolic Constants
// TODO: Come back to this (days of the week and stuff)

enum WeekDays {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
};
enum Months { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

////////////////////////////////
// Macros

#define Stmt(S)                                                                \
  do {                                                                         \
    s                                                                          \
  } while (0)

#define AssertBreak() (*(int *)0 = 0)
#define Assert(c) Stmt(if (!(c)) { AssertBreak(); })
// #define Assert(c) Stmt(if (!(c)) { __debugbreak(); })

#define ArraySize(a) (sizeof(a) / sizeof(*(a)))

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

////////////////////////////////
// Errors
// TODO: Errors

#endif // BASE_H
