| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Set_Volume
This function is used to adjust the volume, 
the max parameter is **120**. And it can automatically 
adjust whether music or sound effects are typed 
on a variable. So if the FGTL_Sound variable is a 
sound effect, then what is set is the sound effect. 
If FGTL_Sound is music, the global volume of the 
music will be the volume you set. And it will also 
make music later whose variable is different in 
volume so it's the same as the previous music volume rules.
```cpp
  void FGTL_Set_Volume(unsigned int volume, FGTL_Sound* sound)
```