# Main CMakeList.txt for qparse

# the project qparse uses c++ compiler
project (qparse CXX)

cmake_minimum_required(VERSION 2.8)

# uses c++11 facility
set(CMAKE_CXX_FLAGS "-MMD -MP -std=c++11")


####
## check libmei library is install or not.
find_path    (LIBMEI_INCLUDE_DIR  NAMES mei/mei.h )
#include_directories(LIBMEI_INCLUDE_DIR)
#MESSAGE( STATUS LIBMEI_INCLUDE_DIR:         ${LIBMEI_INCLUDE_DIR} )
find_library    (LIBMEI_LIBRARY NAMES mei)
#MESSAGE( STATUS LIBMEI_LIBRARY:         ${LIBMEI_LIBRARY} )

if (LIBMEI_INCLUDE_DIR AND LIBMEI_LIBRARY)
        message ("-- Found libmei: ${LIBMEI_INCLUDE_DIR}/mei/,${LIBMEI_LIBRARY}")
        link_libraries(-lmei)
else (LIBMEI_INCLUDE_DIR AND LIBMEI_LIBRARY)
        message(FATAL_ERROR "Could not find mei library. See https://github.com/DDMAL/libmei/")
endif (LIBMEI_INCLUDE_DIR AND LIBMEI_LIBRARY)
####


####
## tell to cmake directories where headers file located
include_directories(
  include
  lib/midifile
  )
## standard header directories
include_directories(/usr/local/include /usr/include)
## standard library directories
link_directories(/usr/local/lib /usr/lib)
####

## set LD flags
set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -pthread" )

## check os type
MESSAGE( STATUS "CMAKE_SYSTEM_NAME:         " ${CMAKE_SYSTEM_NAME} )
string(TOUPPER ${CMAKE_SYSTEM_NAME} CMAKE_UPPER_SYSTEM_NAME)

## specify definitions
add_definitions(
  -DPLATFORM_DARWIN=1
  -DPLATFORM_LINUX=2
  -DPLATFORM_FREEBSD=3
  -DPLATFORM_CYGWIN=4
  -DQP_PLATFORM=PLATFORM_${CMAKE_UPPER_SYSTEM_NAME}
  -DTARGET_QUANT=1
  -DTARGET_EQUIV=2
  -DTARGET_SCHEMA=3
  -DTARGET_MIDI=4
  -DTARGET_MEI=5
  )

## include files for sub-projects
include_directories(
  src/general
  src/schemata
  src/weight
  src/segment
  src/table
  src/parsers
  src/input
  src/output
  src/scoremodel
  )

## compile sub-projects
add_subdirectory(src)
add_subdirectory(lib/midifile)

## common include files
## obsolete
## include_directories(src/targets/quant/scripts)

## sub-projects are given to LD as archive files
##   The ORDER IS IMPORTANT.  (each project possibly depends on lower projects)
set(CMAKE_COMMON_SRC
  midifile
  qparselib
 )

## declare targets
add_executable(squant src/targets/quant/squant.cpp)
target_link_libraries( squant ${CMAKE_COMMON_SRC} )

add_executable(equiv src/targets/equiv/equiv.cpp)
target_link_libraries( equiv ${CMAKE_COMMON_SRC} )

add_executable(schemas src/targets/schema/schemas.cpp)
target_link_libraries( schemas ${CMAKE_COMMON_SRC} )

add_executable(midiutil src/targets/midi/midiutil.cpp)
target_link_libraries( midiutil ${CMAKE_COMMON_SRC} )

#add_executable(meiutil src/targets/mei/meiutil.cpp)
#target_link_libraries( meiutil ${CMAKE_COMMON_SRC} )

