#ifndef _STDALIGN_H
#define _STDALIGN_H

/* stdalign.h - C11 standard header */

#if __POCC__ >= 500
#pragma once
#endif

#if __POCC_STDC_VERSION__ < 201101L

#error <stdalign.h> is only supported in C11 mode

#else /* __POCC_STDC_VERSION__ >= 201101L */

/* macros */
#define alignas  _Alignas
#define alignof  _Alignof
#define __alignas_is_defined  1
#define __alignof_is_defined  1

#endif /* __POCC_STDC_VERSION__ >= 201101L */

#endif /* _STDALIGN_H */
