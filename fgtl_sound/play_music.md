| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Play_Music
This function is used to play sound music. 
If you enter the FGTL_Sound variable with a 
different type, for example FGTL_Sound, it's 
a sound effect type, but you play it on the 
function play sound music, it will terminate 
your program with an error. Whatever the 
reason it will stop your program with an 
error message. And there's something you 
should pay attention to in the first 
parameter section, there's a parameter 
called looping, so the goal is to ask that 
parameter for how many times the music has been played.
```cpp
  void FGTL_Play_Music(unsigned int loop, FGTL_Sound* sound)
```