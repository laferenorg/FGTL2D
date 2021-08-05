| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Execution_Music
This function is used to be a controller 
that can make the music stop or start again, 
or continue the music, so what you need to pay 
attention to is the parameter section. So you 
have to read the enum parameter which is 
FGTL_Sound_Music_Choose. And the second 
parameter must be the type of music.
```cpp
  void FGTL_Execution_Music(FGTL_Sound_Music_Choose choose, \
		FGTL_Sound* sound)
```