| Home                     | Index                                     |
|:-------------------------|:------------------------------------------|
| [Home](../index.html)    | [Index](../first_time/first_time.html)    |

## FGTL_Get_List_Folder
This function is used to get a list of folder in the directory.
Something you should know that the return type is `char*` 
so you have to do the split manually. So I created spaces 
on different filenames. example 
`./build ./test ./include ./main`
```cpp
  char* FGTL_Get_List_Folder(const char* path)
```
