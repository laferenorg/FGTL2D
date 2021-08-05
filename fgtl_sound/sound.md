| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Sound
This is used as a variable that will contain music 
that will be used as a sound effect or as music
```cpp
  typedef struct
  {
	  uint8_t    select;
	  Mix_Chunk* sound_effect;
	  Mix_Music* sound_music;
  } FGTL_Sound;
```