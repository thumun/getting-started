project(CS313-GettingStarted)
cmake_minimum_required(VERSION 3.0)

if (WIN32) # Includes win64 platforms

  find_package(OpenGL REQUIRED)
  find_library(GLEW NAMES glew32s PATHS external/lib/Win32)
  find_library(GLFW NAMES glfw3 PATHS external/lib)

  set(INCLUDE_DIRS
     external/include )

  set(LIBRARY_DIRS
    external/lib)

  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_FLAGS 
     "/wd4018 /wd4244 /wd4305 
     /D_CRT_SECURE_NO_WARNINGS 
     /D_CRT_NONSTDC_NO_DEPRECATE 
     /D NOMINMAX
     /EHsc")

  set(CORE ${GLEW} ${GLFW} opengl32.lib)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

elseif (APPLE)

  message("Build for macOS")
  set(CMAKE_MACOSX_RPATH 1)
  set(CMAKE_CXX_FLAGS "-Wall -Wno-deprecated-declarations -g -stdlib=libc++ -std=c++17")
  set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
  find_library(GL_LIB OpenGL)
  find_library(GLFW glfw)
  add_definitions(-DAPPLE)

  set(INCLUDE_DIRS
    /System/Library/Frameworks
    external/include
    /usr/local/include)

  set(CORE ${GLFW} ${GL_LIB})

elseif (UNIX)

  set(CMAKE_CXX_FLAGS "-Wall -g -std=c++17 -Wno-comment")
  set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
  set(OpenGL_GL_PREFERENCE GLVND)

  FIND_PACKAGE(OpenGL REQUIRED) 
  FIND_PACKAGE(GLEW REQUIRED)

  set(INCLUDE_DIRS . external/include)
  set(LIBRARY_DIRS /usr/X11R6/lib /usr/local/lib)

  add_definitions(-DUNIX)
  set(CORE GLEW glfw GL X11)

endif()

include_directories(${INCLUDE_DIRS})
link_directories(${LIBRARY_DIRS})
add_subdirectory(testGLFW)
