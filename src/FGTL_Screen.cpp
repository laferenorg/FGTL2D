/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Script
 * LICENSE : MIT
 */
/* Include header C++ */
#include <iostream>
#include <string>
#include <cstring>

/* Include header */
#include "FGTL_Screen.h"

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
	FGTL_Color_Pixel default_color) \
{
	/* The width must be equal to 
	 * the character's height, so 
	 * it must be multiplied by 2 
	 */
	screen->width = width * 2;

	/* For the same height */
	screen->height = height;

	/* Make it render to false */
	screen->render = 0;

	/* Make the default color 
	 * the same as the parameter 
	 */
	screen->default_color = default_color;

	/* now create a 2 dimensional array */
	screen->pixel = (FGTL_Pixel*)malloc((screen->width * screen->height) * \
		sizeof(FGTL_Pixel));

	/* Make pixel into default */
	for(int i = 0; i < (screen->width * screen->height); i++) \
	{
		/* Make font text is space */
		screen->pixel[i].font = ' ';

		/* Make font color into default */
		screen->pixel[i].font_color = \
			screen->default_color;

		/* Make background of font is default */
		screen->pixel[i].background_color = \
			screen->default_color;
	}
}

/*
 * @parameter { FGTL_Screen* { screen } }
 * This function for clear console and
 * make into default pixel
 */
void FGTL_Screen_Clear(FGTL_Screen* screen) \
{
	/* Check if has been render */
	if(screen->render == 1) \
	{
		/* This is used for loops with 
		 * the same height as the line deletion 
		 */
		for(int i = 0; i < screen->height; i++) \
		{
			/* This will delete the line above it */
			printf("\033[A\033[2K");
		}

		/* Make render in 
		 * screen into false 
		 */
		screen->render = 0;
	}

	/* Make pixel into default */
	for(int i = 0; i < (screen->width * screen->height); i++) \
	{
		/* Make font text is space */
		screen->pixel[i].font = ' ';

		/* Make font color into default */
		screen->pixel[i].font_color = \
			screen->default_color;

		/* Make background of font is default */
		screen->pixel[i].background_color = \
			screen->default_color;
	}
}

/*
 * @parameter { FGTL_Pixel* { pixel } }
 * This function for convert pixel into
 * char
 */
char* FGTL_CPC(FGTL_Pixel* pixel) \
{
	/* This variable will hold all characters */
	std::string strpixel = "";

	/* Add background specific using rgb */
	strpixel += "\033[48;2;";
	strpixel += std::to_string(pixel->background_color.red) + ";";
	strpixel += std::to_string(pixel->background_color.green) + ";";
	strpixel += std::to_string(pixel->background_color.blue) + "m";

	/* Add foreground specific using rgb */
	strpixel += "\033[38;2;";
	strpixel += std::to_string(pixel->font_color.red) + ";";
	strpixel += std::to_string(pixel->font_color.green) + ";";
	strpixel += std::to_string(pixel->font_color.blue) + "m";

	/* Add character */
	strpixel += pixel->font;

	/* Close character */
	strpixel += "\033[0m\033[0m";

	/* Create output variable 
	 * in type char* 
	 */
	char* output;

	/* Convert std::string into char* */
	output = new char[strpixel.length() + 1];
	strcpy(output, strpixel.c_str());

	/* Return result */
	return output;
}

/*
 * @parameter { FGTL_Screen* { screen } }
 * This function for show pixel
 * into console
 */
void FGTL_Screen_Render(FGTL_Screen* screen) \
{
	/* Make render variable on 
	 * screen into true or another 
	 * is number 
	 */
	screen->render = 1;

	/* Formula for get data 
	 * on 2d array pointer
	 * array + (index_row * columns) + index_cols
	 */
	for(int i = 0; i < screen->height; i++) \
	{
		for(int j = 0; j < screen->width; j++) \
		{
			/* Get character after convert */
			char* out = FGTL_CPC(&(*\
				(screen->pixel + i * screen->width + j)));

			/* Print pixel into console */
			printf("%s", out);

			/* Free memory */
			free(out);
		}
		/* Make new line in console */
		printf("\n");
	}
}