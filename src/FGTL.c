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
#include <SDL2/SDL_mixer.h>

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
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_AUDIO) \
		!= 0) \
	{
		/* Print Error Into Console And exit */
		fprintf(stderr, "[FGTL {Error}]: `%s`\n", SDL_GetError());
		exit(1);
	}

	/* Intialize dependencies sound
	 * and check if dependencies have error
	 */
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, \
		MIX_DEFAULT_FORMAT, 2, 4096) == -1) \
	{
		/* Print Error Into Console And exit */
		fprintf(stderr, "[FGTL {Error}]: `%s`\n", Mix_GetError());
		exit(1);
	}

	/* Amount of channels (Max amount 
	 * of sounds playing at the 
	 * same time) 
	 */
	Mix_AllocateChannels(32);
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

	/* Quit SDL2_mixer */
	Mix_Quit();
}

/*
 * @parameter { function<void>(FGTL_Event*) { update } 
 *				uint16_t 					{ fps }
 *			  }
 * This function for looping program
 * this using parameter function and
 * fps
 */
void FGTL_Loop(void(*update)(FGTL_Event*), uint16_t fps) \
{
	/* Setup variable for 
	 * limiting frames 
	 */
	uint32_t startTicks;

	/* Setup variable 
	 * for looping 
	 */
	uint8_t looping = 1;

	/* Start main looping */
	while(looping == 1) \
	{
		/* Set data variable startTicks
		 * with ticks now 
		 */
		startTicks = SDL_GetTicks();

		/* Setup data for 
		 * handle event 
		 */
		FGTL_Event f_Event;

		/* Get event */
		FGTL_PollEvent(&f_Event);

		/* If event is quit 
		 * make looping into false
		 */
		if(f_Event.type == FGTL_QUIT) \
		{
			looping = 0;
		}

		/* Call function update,
		 * this using for operation
		 * something 
		 */
		update(&f_Event);

		/* Proccess fps or another 
		 * name set frame per seconds 
		 */
		if(1000 / fps > SDL_GetTicks() - startTicks) {
			SDL_Delay(1000 / fps - (SDL_GetTicks() - startTicks));
		}
	}
}