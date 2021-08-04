| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Get_List_File_Extension
This function is used to get files in a 
directory by filtering what files can be 
made into lists. Example can only take 
files with the format `.txt` so the 
calling code: `FGTL_Get_List_File('path/', '.txt')`.
Something you should know that the return type is `char*` 
so you have to do the split manually. So I created spaces 
on different filenames. example 
`main.txt CMakeLists.txt`
```cpp
  char* FGTL_Get_List_File_Extension(const char* path, \
		const char* extension)
```