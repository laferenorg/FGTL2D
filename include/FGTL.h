/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Header
 * LICENSE : MIT
 */
/* Make guard for this header */
#ifndef FGTL_HEADER_H
#define FGTL_HEADER_H

/* Include header event 
 * for handle event 
 */
#include "FGTL_Event.h"

/* Include header system
 * for using system on terminal
 */
#include "FGTL_System.h"

/* Include header scree
 * for manage screen on console
 */
#include "FGTL_Screen.h"

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
/* This header for load script
 * function for help in file
 */
#include "FGTL_File.h"

/* This header for load script
 * function for help in sound 
 */
#include "FGTL_Sound.h"

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

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { function<void>(FGTL_Event*) { update } 
	 *				uint16_t 					{ fps }
	 *			  }
	 * This function for looping program
	 * this using parameter function and
	 * fps
	 */
	void FGTL_Loop(void(*update)(FGTL_Event*), uint16_t fps);
#ifdef __cplusplus
}
#endif

#endif /* End of FGTL_HEADER_H */