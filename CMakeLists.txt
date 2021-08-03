cmake_minimum_required(VERSION 3.0)

# use the variable PROJECT_NAME for changing the target name
set(PROJECT_NAME "fgtl2d" LANGUAGES C CXX)

# Set our project name
project(${PROJECT_NAME} VERSION 1.0.0 
	DESCRIPTION "This is a library for creating 2D Games for terminal and it is only for Linux.")

# directory for easier includes
# anywhere you see include (...) you can check root/cmake for that file
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Set version of C++ compiler
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif(NOT CMAKE_CXX_STANDARD)

# Set version of C compiler
if(NOT CMAKE_C_STANDARD)
	set(CMAKE_C_STANDARD 11)
	set(CMAKE_C_STANDARD_REQUIRED ON)
endif(NOT CMAKE_C_STANDARD)

# Check Required Dependencis
find_package(SDL2 REQUIRED)

# Include directory
include_directories("include/")
include_directories(${SDL2_INCLUDE_DIRS})

# Use all the *.cpp and *.c files we found under this folder for the project
FILE(GLOB SRCS "src/*.cpp" "src/*.c")

# Define the executable
add_library(${PROJECT_NAME} SHARED ${SRCS})

# If Using Property
if(FGTL_USING_PROPERTY)
	set_target_properties(${PROJECT_NAME} 
		PROPERTIES VERSION ${PROJECT_VERSION})
endif(FGTL_USING_PROPERTY)

# Linking
target_link_libraries(${PROJECT_NAME} 
	${SDL2_LIBRARIES} "-lstdc++fs")