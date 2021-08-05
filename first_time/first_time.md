| Home                     |
|:-------------------------|
| [Home](../index.html)    |

## Building and Installation
You are on the first page, and I welcome you. 
And in this section I will give you directions on 
how to build and install it on your computer.
And the first time I will give instructions 
in building, and the first thing to do is to 
install the dependencies used in this project.
- ### Compiler
  Surely you can already guess what compiler should be used.
  From the script, we already know what to use.
  What is needed is a **C** and **C++** compiler.
  You can use a **regular** compiler or use **clang**.
  And what you have to make sure is that you have to 
  support the `std::filesystem` library.
  And also the **C++** compiler already supports **C17**.
- ### Dependencies
  And of course there are dependencies that must be installed and you can see below:
  - **SDL2**
    This project requires **SDL2** too, because there are features that can be used in this project.
    And if you use a **debian** or **ubuntu** operating system you can follow the installation of the 
    following dependencies.
    ```bash
      $ apt install -y libsdl2-dev libsdl2-mixer-dev
    ```   
- ### Tool
  There is a tool that you must install to help 
  the build process of this project. such as the following:
  - **CMake**
    cmake usually helps the build process on this project.
    And **cmake** is not just any version must be **version** `3.(>= 0)`.
    Minor must be more than or equal to 0.
    And if you use a **debian** or **ubuntu** operating system you can follow the installation of the 
    following dependencies.
     ```bash
      $ apt install -y cmake
    ```

- ## Build
  The first time we're going to create a **build** folder, 
  or you can do whatever you want. And both change directory 
  to the build folder, or the folder you like. And thirdly 
  initialize by running cmake you can also add the parameter 
  `-D USING_PROPERTY=<TRUE/FALSE>`, If you don't enter it it 
  will automatically become false, but if you make it true it 
  will make the library that comes out will be named with current 
  version of the project. And the fourth build.
  ```bash
    $ mkdir build
    $ cd build
    $ cmake -D CMAKE_C_COMPILER=<COMPILER C> -D CMAKE_CXX_COMPILER=<COMPILER C++> \
      -D USING_PROPERTY=<FALSE/TRUE> ..
    $ make
  ```
  
- ## Installation
  The first time you create a build, with the first name lib, 
  move it to the `usr/lib` folder. And secondly, create header 
  files to include by creating a FGTL directory in `/usr/include` 
  and moving all header files to `/usr/include/FGTL`.
  ```bash
    [build directory] $ sudo cp lib* /usr/lib
    [build directory] $ cd ..
    [build directpry] $ cd include
    [include directory] $ sudo mkdir /usr/include/FGTL
    [include directory] $ sudo cp *.h /usr/include/FGTL
  ```
  
- ## Build Your Code
  If you already have the code and it's ready to compile you 
  just need to link it with the method. First use flags or 
  Second use target.
  - ### Step #1
    This is usually the one that doesn't use `USING_PROPERTY` on 
    builds by means of regular linking using the `-lfgtl2d` code.
  - ### Step #2
    And this part is usually for those using `USING_PROPERTY` in 
    this project build and you can direct it this way: 
    `<compiler> <code>.<c>/<cpp> /usr/lib/libfgtl2d.so`. That part 
    is the one that doesn't use `USING_PROPERTY`. And this one uses 
    `USING_PROPERTY`: `<compiler> <code>.<c>/<cpp> /usr/lib/libfgtl2d.so.1.0.0`

## Documentation

| Group                  | Pages                                                                                                                            |
|:-----------------------|:---------------------------------------------------------------------------------------------------------------------------------|
| FGTL                   | [FGTL_Init](../fgtl/init.html), [FGTL_Close](../fgtl/quit.html)                                                                  |
| FGTL_FILE_LIST         | [FGTL_Get_List_File](../fgtl_file/get_list_file.html), [FGTL_Get_List_File_Extension](../fgtl_file/get_list_file_extension.html) |
| FGTL_FILE_FOLDER_LIST  | [FGTL_Get_List_Folder](../fgtl_file/get_list_folder.html)                                                                        |
| FGTL_FILE_CHECK        | [FGTL_Its_Folder](../fgtl_file/its_folder.html), [FGTL_Exist_Content](../fgtl_file/exist_content.html)                           |
| FGTL_SOUND_EFFECT      | [FGTL_Play_Effect](../fgtl_sound/play_effect.html)                                                                               |
| FGTL_SOUND_MUSIK       | [FGTL_Play_Music](../fgtl_sound/play_music.html), [FGTL_Execution_Music](../fgtl_sound/execution_music.html)                     |
| FGTL_SOUND_VARIABLE    | [FGTL_Sound](../fgtl_sound/sound.html), [FGTL_Sound_Music_Choose](../fgtl_sound/sound_music_choose.html)                         |
| FGTL_SOUND             | [FGTL_Sound_Free](../fgtl_sound/sound_free.html), [FGTL_Set_Volume](../fgtl_sound/set_volume.html)                               |
| FGTL_SOUND_LOAD        | [FGTL_Load_Sound](../fgtl_sound/load_sound.html)                                                                                 |