cmake_minimum_required(VERSION 3.5)
project(ojcpp)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if (LINUX)
    set(CXX_FLAGS
            -std=c++0x
        )
elseif(APPLE)
    set(CXX_FLAGS
        -std=c++1x
        )
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
elseif(WIN32 )
    # good with clion and visual c++ 2015
    add_definitions(
            -D_WIN32_WINNT=0x0502
    )
    #add_compile_options(/wd4819)
endif()

#MINGW not support thread/mutex on windows
#visual studio not support -pthread
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # using Visual Studio C++
endif()




include_directories(../ojcpp/)
#set(Boost_NO_SYSTEM_PATHS TRUE)
#
#if (Boost_NO_SYSTEM_PATHS)
#    if( WIN32 )
#        set(BOOST_ROOT "C:\\devtool\\boost_1_62")
#        set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib64-msvc-14.0")
#        set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/")
#    else()
#        #if (APPLE)
#        set(BOOST_ROOT "/Users/zhour/devtool/boost")
#        set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib")
#        set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/include")
#    endif()
#    message("use boost lib" ${BOOST_LIBRARY_DIRS}, ${BOOST_INCLUDE_DIRS})
#endif (Boost_NO_SYSTEM_PATHS)



include_directories(${PROJECT_SOURCE_DIR})
message("project path:" ${PROJECT_SOURCE_DIR})

# src files =======================================
file(GLOB_RECURSE CPP11 "cpp11/*.cpp")
file(GLOB_RECURSE MAIN "../ojcpp/codech/*.cpp")


set(SOURCE_FILES
        ${CPP11}
        ${MAIN}
        )

add_executable(vcprj ${SOURCE_FILES})

