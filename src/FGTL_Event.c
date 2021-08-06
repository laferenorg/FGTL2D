/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Script
 * LICENSE : MIT
 */
/* Include header C */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Include header SDL2 */
#include <SDL2/SDL.h>

/* Include header */
#include "FGTL_System.h"
#include "FGTL_Event.h"

/* This variable used for event key 
 * pressed and release, this type as bool 
 * because this using c language this changed
 * as uint8_t */
uint8_t FGTL_KEY_PRESSED_BOOL = 0;
uint8_t FGTL_KEY_RELEASE_BOOL = 0;

/* This variable used for 
 * contain user input character 
 */
char FGTL_CHARACTER_INPUT_USER;

/*
 * @parameter { FGTL_Event* { f_Event } }
 * This function for get key on press or release
 * and get key down or release
 */
void FGTL_Event_Key(FGTL_Event* f_Event) \
{
	/* Setup variable
	 * for get input character
	 * from user
	 */
	char characterInput;

	/* Check if user give input */
	if(FGTL_getInput(&characterInput) == 1) \
	{
		/* Change boolean pressed into true,
		 * and release into false 
		 */
		FGTL_KEY_PRESSED_BOOL = 1;
		FGTL_KEY_RELEASE_BOOL = 0;
		
		/* If character input is not equal into
		 * character global 
		 */
		if(characterInput != FGTL_CHARACTER_INPUT_USER) \
		{
			FGTL_CHARACTER_INPUT_USER = characterInput;
		}

		/* Delete character input 
		 * user on console 
		 */
		printf("\b\b");
	} else if(FGTL_KEY_RELEASE_BOOL == 0 && \
		FGTL_KEY_PRESSED_BOOL == 1) \
	{
		/* If user not press key 
		 * and pressed is true 
		 */
		FGTL_KEY_PRESSED_BOOL = 0;
		FGTL_KEY_RELEASE_BOOL = 1;
	} else \
	{
		/* If user not press key and 
		 * pressed is false 
		 */
		FGTL_KEY_PRESSED_BOOL = 0;
		FGTL_KEY_RELEASE_BOOL = 0;
	}

	/* Set character key
	 * in event
	 */
	if(FGTL_KEY_PRESSED_BOOL == 0 && \
		FGTL_KEY_RELEASE_BOOL == 0) \
	{
		f_Event->key = '\0';
	}

	/* If one of the variables is true, 
	 * press or release will make the 
	 * character in the event a global 
	 * user input character
	 *
	 * And set type into pressed or
	 * release
	 */
	if(FGTL_KEY_PRESSED_BOOL == 1 || \
		FGTL_KEY_RELEASE_BOOL == 1) \
	{
		f_Event->key = \
			FGTL_CHARACTER_INPUT_USER;

		/* If pressed */
		if(FGTL_KEY_PRESSED_BOOL == 1) \
		{
			f_Event->type = FGTL_KeyPressed;
		}

		/* If Release */
		if(FGTL_KEY_RELEASE_BOOL == 1) \
		{
			f_Event->type = FGTL_KeyRelease;
		}
	}
}

/*
 * @parameter { FGTL_Event* { f_Event } }
 * This function for get event from
 * SDL2
 */
void FGTL_Event_SDL(FGTL_Event* f_Event) \
{
	/* Setup data for 
	 * handle event 
	 * from SDL2
	 */
	SDL_Event s_Event;

	/* If have event */
	if(SDL_PollEvent(&s_Event)) \
	{
		/* If have some event */
		/* Handling event for quit, 
		 * if on terminating, close 
		 */
		switch(s_Event.type) \
		{
			/* If SDL event 
			 * is quit 
			 */
			case SDL_QUIT: \
			{
				/* make event 
				 * type is quit 
				 */
				f_Event->type = FGTL_QUIT;
			}
			break;

			/* If SDL event 
			 * is terminating 
			 */
			case SDL_APP_TERMINATING: \
			{
				/* make event 
				 * type is quit 
				 */
				f_Event->type = FGTL_QUIT;
			}
			break;
		}
	}
}

/*
 * @parameter { FGTL_Event* { f_Event } }
 * This function for get event
 */
void FGTL_PollEvent(FGTL_Event* f_Event) \
{
	/* Set event into nope */
	f_Event->type = FGTL_NOPE;

	/* This for handle event
	 * key press or release 
	 */
	FGTL_Event_Key(f_Event);

	/* This for handle 
	 * event from SDL2 
	 */
	FGTL_Event_SDL(f_Event);
}