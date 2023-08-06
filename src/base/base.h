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

typedef struct Vec2_I32 {
  I32 x;
  I32 y;
} Vec2_I32;

typedef struct Vec2 {
  F32 x;
  F32 y;
} Vec2;

typedef struct Vec2_F64 {
  F64 x;
  F64 y;
} Vec2_F64;

typedef struct Vec3 {
  F32 x;
  F32 y;
  F32 z;
} Vec3;

////////////////////////////////
// Constants
// TODO: Come back to this (don't know what to add here now)

#define MaxI8 255
#define MaxI16 65535
#define MaxI32 0xFFFFFFFF
#define MaxI64 0xFFFFFFFFFFFFFFFF

#define MaxU8 256

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

#define Stmt(s)                                                                \
  do {                                                                         \
    s                                                                          \
  } while (0)

#define flush fflush(stdout)
#define trace Statement(printf("%s:%d: Trace\n", FILE_NAME, __LINE__); flush;)
#define unreachable                                                            \
  Statement(                                                                   \
      printf("Unreachable reached. In %s on line %d\n", FILE_NAME, __LINE__);  \
      flush;)

#if COMPILER_CLANG || COMPILER_GCC
#define AssertBreak() __builtin_trap()
#else
#define AssertBreak() (*(int *)0 = 0)
#endif

#define Assert(c) Stmt(if (!(c)) { AssertBreak(); })

// #define Assert(c) Stmt(if (!(c)) { __debugbreak(); })

#define ArraySize(a) (sizeof(a) / sizeof(*(a)))

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

////////////////////////////////
// Errors
// TODO: Errors

#endif // BASE_H
