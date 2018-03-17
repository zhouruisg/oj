cmake_minimum_required(VERSION 3.8)
project(ojcpp)

set(CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if (LINUX)
    set(CXX_FLAGS
            -std=c++0x
        )
elseif(APPLE)
    set(CXX_FLAGS
        -std=c++1y
        )
endif()

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

set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_definitions(-DBOOST_LOG_DYN_LINK)
find_package(Boost COMPONENTS system filesystem thread-mt log log_setup REQUIRED)
#find_package(Protobuf)
find_library(BOOSTPO_LIBRARY
        NAMES  boost_program_options
        HINTS "${BOOST_LIBRARY_DIRS}"
        )

include_directories(${BOOST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
message("project path:" ${PROJECT_SOURCE_DIR})
message("boost po library:" ${BOOSTPO_LIBRARY})

# src files =======================================
file(GLOB_RECURSE LEETCODE "leetcode/*.cpp")
file(GLOB_RECURSE MAIN "codech/*.cpp")

set(SOURCE_FILES
        ${LEETCODE}
        ${MAIN}
        leetcode/350_e_intersectiontwoarray.cpp)

add_executable(ojcpp ${SOURCE_FILES})
target_link_libraries(ojcpp ${Boost_LIBRARIES})
