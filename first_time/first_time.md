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
      $ apt install -y libsdl2-dev
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
