#ifndef _STDNORETURN_H
#define _STDNORETURN_H

/* stdnoreturn.h - C11 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#if __POCC_STDC_VERSION__ < 201101L

#error <stdnoreturn.h> is only supported in C11 mode

#else /* __POCC_STDC_VERSION__ >= 201101L */

/* macros */
#define noreturn  _Noreturn

#endif /* __POCC_STDC_VERSION__ >= 201101L */

#endif /* _STDNORETURN_H */
