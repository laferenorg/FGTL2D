/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Script
 * LICENSE : MIT
 */
/* Include header C */
#include <stdio.h>
#include <stdlib.h>

/* Include header SDL2 */
#include <SDL2/SDL.h>

/* Include header */
#include "FGTL.h"

/*
 * @parameter { void }
 * This function for intialize dependencies
 * like SDL2, this for using features
 * in dependencies
 */
void FGTL_Init(void) \
{
	/* This section on if statement is for intialize
	 * and check if intialize has been failed
	 * and show into console what's error
	 */
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS) == 0) \
	{
		/* Print Error Into Console And exit */
		fprintf(stderr, "[FGTL {Error}]: `%s`\n", SDL_GetError());
		exit(1);
	}
}

/*
 * @parameter { void }
 * This function for quit all dependencies
 */
void FGTL_Close(void) \
{
	/* Quit SDL2 i don't know for what i must be
	 * Closed this dependencies but for secure
	 * i make quit dependencies SDL2
	 */
	SDL_Quit();
}