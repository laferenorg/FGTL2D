/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Header
 * LICENSE : MIT
 */
/* Make guard for this header */
#ifndef FGTL_EVENT_H
#define FGTL_EVENT_H

/* This enum type 
 * for get event type 
 */
enum _FGTL_Type \
{
	FGTL_NOPE,
	FGTL_QUIT,
	FGTL_KeyPressed,
	FGTL_KeyRelease
};

typedef enum _FGTL_Type FGTL_Type;

/* This structure for 
 * get handle event 
 */
struct _FGTL_Event \
{
	FGTL_Type type;
	char key;
};

typedef struct _FGTL_Event FGTL_Event;

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
	 * @parameter { FGTL_Event* { f_Event } }
	 * This function for get event
	 */
	void FGTL_PollEvent(FGTL_Event* f_Event);
#ifdef __cplusplus
}
#endif

#endif /* End of FGTL_EVENT_H */