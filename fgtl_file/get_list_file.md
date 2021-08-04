| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Get_List_File
This function is used to get a list of files in the directory.
Something you should know that the return type is `char*` 
so you have to do the split manually. So I created spaces 
on different filenames. example 
`main.txt CMakeLists.txt main.cpp main.out`
```cpp
  char* FGTL_Get_List_File(const char* path)
```
