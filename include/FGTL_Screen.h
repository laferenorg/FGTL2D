/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Header
 * LICENSE : MIT
 */
/* Make guard for this header */
#ifndef FGTL_SCREEN_H
#define FGTL_SCREEN_H

/* Include header C */
#include <stdint.h>

/* This structure for 
 * color pixel on console 
 */
struct _FGTL_Color_Pixel \
{
	/* Specific color: red, gree, blue */
	uint8_t red, green, blue;
};

typedef struct _FGTL_Color_Pixel FGTL_Color_Pixel;

/* This structure for
 * show pixel into console 
 */
struct _FGTL_Pixel \
{
	char font;
	FGTL_Color_Pixel font_color;
	FGTL_Color_Pixel background_color;
};

typedef struct _FGTL_Pixel FGTL_Pixel;

/* This structure for
 * Be vital in pixels on console 
 */
struct _FGTL_Screen \
{
	uint8_t render;
	FGTL_Pixel* pixel;
	unsigned int width, height;
	FGTL_Color_Pixel default_color;
};

typedef struct _FGTL_Screen FGTL_Screen;

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { FGTL_Screen*     { screen },
	 * 				unsigned int     { width },
	 *				unsigned int     { height },
	 *				FGTL_Color_Pixel { default_color }
	 *			  }
	 * This function for initialize screen
	 */
	void FGTL_Init_Screen(FGTL_Screen* screen, \
		unsigned int width, unsigned int height, \
		FGTL_Color_Pixel default_color);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { FGTL_Screen* { screen } }
	 * This function for clear console and
	 * make into default pixel
	 */
	void FGTL_Screen_Clear(FGTL_Screen* screen);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { FGTL_Pixel* { pixel } }
	 * This function for convert pixel into
	 * char
	 */
	char* FGTL_CPC(FGTL_Pixel* pixel);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { FGTL_Screen* { screen } }
	 * This function for show pixel
	 * into console
	 */
	void FGTL_Screen_Render(FGTL_Screen* screen);

#ifdef __cplusplus
}
#endif

#endif /* End of FGTL_SCREEN_H */