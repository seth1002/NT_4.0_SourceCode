/****************************Module*Header***********************************\
* Module Name: WASSERT
*
* Module Descripton: Quick Win32 assert code.
*
* Warnings:
*
* Created: 15 July 1993
*
* Author: Raymond E. Endres   [rayen@microsoft.com]
\****************************************************************************/

#ifdef NODEBUG
   #define ASSERT(exp) ((void)0)
#else
   void vAssert(PTSTR pszExp, PTSTR pszFile, int iLine);
   #define ASSERT(exp) (void)( (exp) || (vAssert(TEXT(#exp), TEXT(__FILE__), __LINE__), 0) )
#endif
