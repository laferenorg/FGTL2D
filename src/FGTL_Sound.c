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
#include "FGTL_Sound.h"
#include "FGTL_File.h"

/*
 * @parameter { uint8_t              { music },
 *              const char* 		 { sound path }
 *				FGTL_Sound* 		 { sound }
 *			   }
 * This function for Load Sound
 * this function first check if load is music
 * and the seconds get sound from path,
 * third refrench variable
 */
void FGTL_Load_Sound(uint8_t music, const char* sound_path, \
	FGTL_Sound* sound) \
{
	/* Check if not file exist 
	 * or is directory 
	 */
	if(!FGTL_Exist_Content(sound_path)) \
	{
		/* Print Error Into Console And exit */
		fprintf(stderr, "[FGTL {Error}]: `Invalid file sound: %s`\n", \
			sound_path);
		exit(1);
	}

	/* If this function it's 
	 * load for music 
	 */	
	if(music != 0) \
	{
		/* Change Select 
		 * of variable sound
		 * into number 1 
		 */
		sound->select = 1;

		/* Now load sound
		 * type music
		 */
		sound->sound_music = Mix_LoadMUS(\
			sound_path);
	} else \
	{
		/* If this function 
		 * load effect 
		 */
		/* Change Select 
		 * of variable sound
		 * into number 0 
		 */
		sound->select = 0;

		/* Now load sound
		 * type effect
		 */
		sound->sound_effect = Mix_LoadWAV(\
			sound_path);
	}
}

/*
 * @parameter { unsigned int { volum },
 *				FGTL_Sound*  { sound }
 *			   }
 * This function for Load Sound
 */
void FGTL_Set_Volume(unsigned int volume, FGTL_Sound* sound) \
{
	/* Check the volume if 
	 * it's not out of bounds 
	 */
	volume = (volume > MIX_MAX_VOLUME) \
		? MIX_MAX_VOLUME : volume;

	/* Check the sound 
	 * will set volume 
	 */
	if(sound->select == 0) \
	{
		/* If this function will 
		 * set volume of type effect 
		 */
		Mix_VolumeChunk(sound->sound_effect, \
			volume);
	} else \
	{
		/* If this function will 
		 * set volume of type sound 
		 */
		Mix_VolumeMusic(volume);
	}
}

/*
 * @parameter { FGTL_Sound*  { sound } }
 * This function for Play sound effect
 */
void FGTL_Play_Effect(FGTL_Sound* sound) \
{
	/* Check if sound 
	 * variable is type 
	 * effect 
	 */
	if(sound->select != 0) \
	{
		/* Print Error Into Console And exit */
		fprintf(stderr, "[FGTL {Error}]: `Can't play effect, \
			Invalid variable sound: %p`\n", \
			sound);
		exit(1);
	}

	/* After check, Play effect */
	/* -1 here means we let SDL_mixer 
	 * pick the first channel that 
	 * is free */
	/* If no channel is free 
	 * it'll return an err code. 
	 */
	Mix_PlayChannel(-1, sound->sound_effect, 0);
}

/*
 * @parameter { FGTL_Sound*  { sound } }
 * This function for Play sound music
 */
void FGTL_Play_Music(unsigned int loop, FGTL_Sound* sound) \
{
	/* Check if sound 
	 * variable is type 
	 * music 
	 */
	if(sound->select != 1) \
	{
		/* Print Error Into Console And exit */
		fprintf(stderr, "[FGTL {Error}]: `Can't play music, \
			Invalid variable sound: %p`\n", \
			sound);
		exit(1);
	}

	/* After check, Play music */
	Mix_PlayMusic(sound->sound_music, loop);
}

/*
 * @parameter { FGTL_Sound_Music_Choose { choose }
 *				FGTL_Sound*  			{ sound } 
 *			  }
 * This function for execution run sound music,
 * like resume, pause, and rewind
 */
void FGTL_Execution_Music(FGTL_Sound_Music_Choose choose, 
	FGTL_Sound* sound) \
{
	/* Check if sound 
	 * variable is type 
	 * music 
	 */
	if(sound->select != 1) \
	{
		/* Print Error Into Console And exit */
		fprintf(stderr, "[FGTL {Error}]: `Can't play music, \
			Invalid variable sound: %p`\n", \
			sound);
		exit(1);
	}

	/* After check, Play music */
	/* Now let's do switch case */
	switch(choose) \
	{
		/* If the parameter chooses 
		 * to resume music 
		 */
		case Sound_Music_Resume: \
		{
			/* Run function 
			 * from SDL2_mixer 
			 * for resume music
			 */
			Mix_ResumeMusic();
		}
		break;

		/* If the parameter chooses 
		 * to Pause music 
		 */
		case Sound_Music_Pause: \
		{
			/* Run function 
			 * from SDL2_mixer 
			 * for Pause music
			 */
			Mix_PauseMusic();
		}
		break;

		/* If the parameter chooses 
		 * to rewind music 
		 */
		case Sound_Music_Rewind: \
		{
			/* Run function 
			 * from SDL2_mixer 
			 * for rewind music
			 */
			Mix_RewindMusic();
		}
		break;
	}
}

/*
 * @parameter { FGTL_Sound* { sound } }
 * This function for free memory of sound
 */
void FGTL_Sound_Free(FGTL_Sound* sound) \
{
	/* Check sound type effect */
	if(sound->select != 0) \
	{
		/* If type of sound is music */
		Mix_FreeMusic(sound->sound_music);
	} else \
	{
		/* If type of sound is effect */
		Mix_FreeChunk(sound->sound_effect);
	}
}