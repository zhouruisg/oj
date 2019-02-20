cmake_minimum_required(VERSION 3.5)
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
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
elseif(WIN32 )
    # good with clion and visual c++ 2015
    add_definitions(
            -D_WIN32_WINNT=0x0502
    )
    #add_compile_options(/wd4819)
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



include_directories(${PROJECT_SOURCE_DIR})
message("project path:" ${PROJECT_SOURCE_DIR})

# src files =======================================
file(GLOB_RECURSE LEETCODE "leetcode/*.cpp")
file(GLOB_RECURSE HHT "hht/*.cpp")
file(GLOB_RECURSE MAIN "codech/*.cpp")
file(GLOB_RECURSE CPP11 "cpp11/*.cpp")

set(SOURCE_FILES
        ${LEETCODE}
        ${MAIN}
        ${HHT}
        ${CPP11}
        hht/025_bstsum.cpp leetcode/004_h_medianofsortedarray.cpp leetcode/023_mergeksortedlist.cpp leetcode/124_bstmaxsum.cpp leetcode/076_h_minwinsubstr.cpp leetcode/003_m_longestsubstrwithoutrepeat.cpp leetcode/005_m_longestpalindromicsubstr.cpp leetcode/006_m_zigzagconversion.cpp leetcode/010_h_regularexpmatching.cpp leetcode/007_e_reverseint.cpp leetcode/009_e_palindromenumber.cpp leetcode/012_m_integertoroman.cpp leetcode/042_h_traprainwater.cpp leetcode/013_e_roman2integer.cpp leetcode/018_m_4sum.cpp leetcode/019_m_removenthnode.cpp leetcode/026_e_removeduplicatefromsortarray.cpp leetcode/031_m_nextpermutation.cpp)

add_executable(ojcpp ${SOURCE_FILES})

