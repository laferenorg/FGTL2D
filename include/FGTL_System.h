/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Header
 * LICENSE : MIT
 */
/* Make guard for this header */
#ifndef FGTL_SYSTEM_HEADER_H
#define FGTL_SYSTEM_HEADER_H

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
	 * This function for reset terminal
	 * mode
	 */
	void FGTL_reset_terminal_mode(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * This function for set conio terminal
	 * mode
	 */
	void FGTL_set_conio_terminal_mode(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * kbhit() is present in conio.h and 
	 * used to determine if a key has 
	 * been pressed or not.
	 */
	int FGTL_kbhit(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { int { echo } }
	 * Intialize termios
	 */
	void FGTL_initTermios(int echo);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * reset termios
	 */
	void FGTL_resetTermios(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * read 1 character - echo 
	 * defines echo mode
	 */
	char FGTL_getch_(int echo);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * Read 1 character without echo
	 */
	char FGTL_getch(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * Read 1 character with echo
	 */
	char FGTL_getche(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { void }
	 * Get input
	 */
	int FGTL_getInput(char *c);
#ifdef __cplusplus
}
#endif

#endif /* End of FGTL_SYSTEM_HEADER_H */