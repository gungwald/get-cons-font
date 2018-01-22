/*
 * win32errortext.h
 *
 *  Created on: Jul 4, 2012
 *      Author: Bill
 */

#ifndef WIN32ERRORTEXT_H_
#define WIN32ERRORTEXT_H_

#include <Windows.h>

extern wchar_t *getErrorText(DWORD dwLastError, wchar_t *text, size_t textCapacity);
extern void writeErrorMessage(wchar_t *failedFuncName, DWORD dwLastError);


#endif /* WIN32ERRORTEXT_H_ */
