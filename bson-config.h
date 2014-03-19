/*
 * Copyright 2013 MongoDB Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef BSON_CONFIG_H
#define BSON_CONFIG_H

/*
 * BSON_BYTE_ORDER is used to define the current endianness.  If big endian, it
 * will be 4321. If little endian, it will be 1234.
 */

/*
 * BSON_OS will be defined to 1 or 2 depending if we are on a UNIX-like system
 * or Windows. UNIX is 1, Windows is 2.
 */
#ifdef _MSC_VER
   #define BSON_OS 2
   #define BSON_BYTE_ORDER 1234
#else
   #define BSON_OS 1
   #define BSON_BYTE_ORDER 4321
#endif

// SOMETIMES MINGW requires hacks. So we need special definition
#ifdef BOOST_WINDOWS
   #ifdef BOOST_GCC
      #define MNT_BSON_WINMINGW
   #endif
#endif

/************************************/

#define BSON_HAVE_STDBOOL_H 0
#if BSON_HAVE_STDBOOL_H != 1
# undef BSON_HAVE_STDBOOL_H
#endif

 /*
 * Define to 1 if your system requires {} around PTHREAD_ONCE_INIT.
 * This is typically just Solaris 8-10.
 */
#define BSON_PTHREAD_ONCE_INIT_NEEDS_BRACES 0
#if BSON_PTHREAD_ONCE_INIT_NEEDS_BRACES != 1
# undef BSON_PTHREAD_ONCE_INIT_NEEDS_BRACES
#endif


/*
 * Define to 1 if you have clock_gettime() available.
 */
#define BSON_HAVE_CLOCK_GETTIME 0
#if BSON_HAVE_CLOCK_GETTIME != 1
# undef BSON_HAVE_CLOCK_GETTIME
#endif


/*
 * Define to 1 if you have strnlen available on your platform.
 */
#define BSON_HAVE_STRNLEN 0
#if BSON_HAVE_STRNLEN != 1
# undef BSON_HAVE_STRNLEN
#endif


/*
 * Define to 1 if you have strnlen available on your platform.
 */
#define BSON_HAVE_SNPRINTF 0
#if BSON_HAVE_SNPRINTF != 1
# undef BSON_HAVE_SNPRINTF
#endif


/*
 * Define to 1 if 32-bit atomics are not available and pthreads should be
 * used to emulate them.
 */
#define BSON_WITH_OID32_PT 0
#if BSON_WITH_OID32_PT != 1
# undef BSON_WITH_OID32_PT
#endif


/*
 * Define to 1 if 64-bit atomics are not available and pthreads should be
 * used to emulate them.
 */
#define BSON_WITH_OID64_PT 0
#if BSON_WITH_OID64_PT != 1
# undef BSON_WITH_OID64_PT
#endif


#endif /* BSON_CONFIG_H */
