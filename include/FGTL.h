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
 * @parameter { void }
 * This function for intialize dependencies
 * like SDL2, this for using features
 * in dependencies
 */
void FGTL_Init(void);

/*
 * @parameter { void }
 * This function for quit all dependencies
 */
void FGTL_Close(void);

#endif /* End of FGTL_HEADER_H */