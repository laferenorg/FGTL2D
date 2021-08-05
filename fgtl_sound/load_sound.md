| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Load_Sound
This function is used to load sound effects or music, 
what needs to be considered is the parameters. 
The first parameter is the question whether you want 
to load music or sound effects. If yes, make `1` or `true`, 
you should make 1 because **c language** does not provide 
**true** as a boolean, otherwise make `0 ` or `false`. 
The second parameter is the path to the music file or sound 
effect. And you must know the third parameter by reading 
the FGTL_Sound variable documentation.
```cpp
  void FGTL_Load_Sound(uint8_t music, const char* sound_path, \
		FGTL_Sound* sound)
```