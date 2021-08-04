/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Header
 * LICENSE : MIT
 */
/* Make guard for this header */
#ifndef FGTL_SOUND_HEADER_H
#define FGTL_SOUND_HEADER_H

/* Include header SDL2 */
#include <SDL2/SDL_mixer.h>

/* This structure for load sound,
 * In intialize this will be free 
 * Variable if not used, example
 * if variable wav in using, But
 * music is not, Variable music
 * will be free
 */
struct _FGTL_Sound \
{
	uint8_t    select;
	Mix_Chunk* sound_effect;
	Mix_Music* sound_music;
};

typedef struct _FGTL_Sound FGTL_Sound;

/* This enum is to choose 
 * what work to do in managing 
 * the sound music
 */
enum _FGTL_Sound_Music_Choose \
{
	Sound_Music_Resume,
	Sound_Music_Pause,
	Sound_Music_Rewind
};

typedef enum _FGTL_Sound_Music_Choose \
	FGTL_Sound_Music_Choose;

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
		FGTL_Sound* sound);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { unsigned int { volum },
	 *				FGTL_Sound*  { sound }
	 *			   }
	 * This function for Set sound Sound
	 * this will automatically check what
	 * variable will set sound
	 */
	void FGTL_Set_Volume(unsigned int volume, FGTL_Sound* sound);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { FGTL_Sound*  { sound } }
	 * This function for Play sound effect
	 */
	void FGTL_Play_Effect(FGTL_Sound* sound);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { unsigned int { loop }
	 *				FGTL_Sound*  { sound } 
	 *			  }
	 * This function for Play sound music
	 */
	void FGTL_Play_Music(unsigned int loop, FGTL_Sound* sound);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { FGTL_Sound_Music_Choose { choose }
	 *				FGTL_Sound*  			{ sound } 
	 *			  }
	 * This function for execution run sound music,
	 * like resume, pause, and rewind
	 */
	void FGTL_Execution_Music(FGTL_Sound_Music_Choose choose, \
		FGTL_Sound* sound);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*
	 * @parameter { FGTL_Sound* { sound } }
	 * This function for free memory of sound
	 */
	void FGTL_Sound_Free(FGTL_Sound* sound);

#ifdef __cplusplus
}
#endif

#endif /* End of FGTL_SOUND_HEADER_H */