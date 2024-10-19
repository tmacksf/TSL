// Base file

#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>

#if __APPLE__
#include <_types/_uint8_t.h>
#include <sys/_types/_int64_t.h>
#include <sys/_types/_int8_t.h>
#endif

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
/* Types */
#include <stdint.h>
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

////////////////////////////////
/* Compound Types */
/* TODO: Don't know what to do here but like vectors */

typedef struct Vec2_I32 {
  i32 x;
  i32 y;
} Vec2_I32;

typedef struct Vec2 {
  f32 x;
  f32 y;
} Vec2;

typedef struct Vec2_F64 {
  f64 x;
  f64 y;
} Vec2_F64;

typedef struct Vec3 {
  f32 x;
  f32 y;
  f32 z;
} Vec3;

////////////////////////////////
/* Constants */
/* TODO: Come back to this (don't know what to add here now) */

#include <limits.h>

////////////////////////////////
/* Symbolic Constants */
/* TODO: Come back to this (days of the week and stuff) */

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
/* Macros */

#define Stmt(s)                                                                \
  do {                                                                         \
    s                                                                          \
  } while (0)

#define flush fflush(stdout)
#define TRACE Statement(printf("%s:%d: Trace\n", FILE_NAME, __LINE__); flush;)
#define UNREACHABLE                                                            \
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
/* Errors */
// TODO: Errors

#endif // BASE_H
