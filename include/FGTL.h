/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Header
 * LICENSE : MIT
 */
/* Make guard for this header */
#ifndef FGTL_HEADER_H
#define FGTL_HEADER_H

/*
 * If you see code
 * #ifdef __cplusplus
 * extern "C" {
 * #endif
 * 
 * This used for, make if you use the c++ compiler, 
 * it will be extern in c language
 */

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * This function for intialize dependencies
	 * like SDL2, this for using features
	 * in dependencies
	 */
	void FGTL_Init(void);
#ifdef __cplusplus
}
#endif

/* The section to load the header 
 * file in the middle of the init 
 * function and the quit function 
 */
#include "FGTL_File.h"

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * This function for quit all dependencies
	 */
	void FGTL_Close(void);
#ifdef __cplusplus
}
#endif

#endif /* End of FGTL_HEADER_H */