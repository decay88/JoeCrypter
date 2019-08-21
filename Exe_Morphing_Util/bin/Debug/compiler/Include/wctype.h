#ifndef _WCTYPE_H
#define _WCTYPE_H

/* wctype.h - C99 standard header */

#if __POCC__ >= 500
#pragma once
#endif

/* macros */
#define WEOF  ((wint_t)(-1))

/* type definitions */
#ifndef _WINT_T_DEFINED
#define _WINT_T_DEFINED
typedef unsigned short wint_t;
#endif /* _WINT_T_DEFINED */

typedef unsigned int wctrans_t;
typedef unsigned int wctype_t;

/* declarations */
extern int __cdecl iswalnum(wint_t);
extern int __cdecl iswalpha(wint_t);
extern int __cdecl iswcntrl(wint_t);
extern int __cdecl iswdigit(wint_t);
extern int __cdecl iswgraph(wint_t);
extern int __cdecl iswlower(wint_t);
extern int __cdecl iswprint(wint_t);
extern int __cdecl iswpunct(wint_t);
extern int __cdecl iswspace(wint_t);
extern int __cdecl iswblank(wint_t);
extern int __cdecl iswupper(wint_t);
extern int __cdecl iswxdigit(wint_t);
extern int __cdecl _iswascii(wint_t);
extern int __cdecl iswctype(wint_t, wctype_t);
extern wint_t __cdecl towlower(wint_t);
extern wint_t __cdecl towupper(wint_t);
extern wint_t __cdecl towctrans(wint_t, wctrans_t);
extern wctrans_t __cdecl wctrans(const char *);
extern wctype_t __cdecl wctype(const char *);

/* internal stuff */
extern int __cdecl __iswctype(wint_t, wctype_t);
extern wint_t __cdecl __towctrans(wint_t, wctrans_t);

/* macro overrides */
#define iswalnum(wc)  __iswctype(wc,1)
#define iswalpha(wc)  __iswctype(wc,2)
#define iswcntrl(wc)  __iswctype(wc,3)
#define iswdigit(wc)  __iswctype(wc,4)
#define iswgraph(wc)  __iswctype(wc,5)
#define iswlower(wc)  __iswctype(wc,6)
#define iswprint(wc)  __iswctype(wc,7)
#define iswpunct(wc)  __iswctype(wc,8)
#define iswspace(wc)  __iswctype(wc,9)
#define iswblank(wc)  __iswctype(wc,12)
#define iswupper(wc)  __iswctype(wc,10)
#define iswxdigit(wc)  __iswctype(wc,11)
#define _iswascii(wc)  __iswctype(wc,13)
#define iswctype(wc,desc)  __iswctype(wc,desc)
#define towlower(wc)  __towctrans(wc,1)
#define towupper(wc)  __towctrans(wc,2)
#define towctrans(wc,desc)  __towctrans(wc,desc)

#ifdef __POCC__OLDNAMES
extern int __cdecl iswascii(wint_t);
#define iswascii(c)  __iswctype(wc,13)
#endif /* __POCC__OLDNAMES */

#endif /* _WCTYPE_H */
