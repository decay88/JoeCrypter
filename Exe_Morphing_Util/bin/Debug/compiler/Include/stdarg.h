#ifndef _STDARG_H
#define _STDARG_H

/* stdarg.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#include <crtdef.h>

/* type definitions */
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
typedef _CRTVAP char *va_list;
#endif /* _VA_LIST_DEFINED */

/* macros */
#if __POCC_TARGET__ == 1

#define va_arg(ap,ty)      (*(ty *)(((ap) += __va_align(ty)) - __va_align(ty)))
#define va_end(ap)         (void)((ap) = 0)
#define va_start(ap,arg0)  (void)((ap) = (char *)&(arg0) + __va_align(arg0))
#define va_copy(ap,sp)     (void)((ap) = (sp))
#define __va_align(ty)     ((sizeof(ty) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#elif __POCC_TARGET__ == 3

#define va_arg(ap,ty)      ((sizeof(ty) > sizeof(long long) || (sizeof(ty) & (sizeof(ty) - 1)) != 0) ? \
                                **(ty **)((ap += sizeof(long long)) - sizeof(long long)) : \
                                 *(ty  *)((ap += sizeof(long long)) - sizeof(long long)))
#define va_end(ap)         (void)((ap) = 0)
#define va_start(ap,arg0)  (void)((ap) = (char *)&(arg0) + sizeof(long long))
#define va_copy(ap,sp)     (void)((ap) = (sp))

#endif /* __POCC_TARGET__ */

#endif /* _STDARG_H */

