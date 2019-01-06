cmake_minimum_required(VERSION 2.8)
project(ida-libbfd-loader)

#Don't use the RPATH on OS X.
set(CMAKE_MACOSX_RPATH 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)


set(SOURCES
    ida-libbfd-loader.cpp
)

#Find libbfd
find_package(Bfd)

if(LIBBFD_FOUND)
  add_definitions(-DHAVE_LIBBFD=1)
  find_package(Intl)
  if(Intl_FOUND)
  	LIST(APPEND LIBBFD_LIBRARIES ${Intl_LIBRARIES})
  endif()
  find_package(Iconv)
  if(Iconv_FOUND)
  	LIST(APPEND LIBBFD_LIBRARIES ${Iconv_LIBRARIES})
  endif()
  find_package(ZLIB)
  if(ZLIB_FOUND)
  	LIST(APPEND LIBBFD_LIBRARIES ${ZLIB_LIBRARIES})
  endif()
endif()

include_directories(${LIBBFD_INCLUDE_DIRS})

find_package(IDA)
include_directories(${IDA_INCLUDE_DIR})
include_directories(${IDA_SDK_DIR}/ldr)
include_directories(${ELF_COMMON_PATH})

add_definitions(${IDA_DEFINITIONS})
add_definitions(-DUSE_STANDARD_FILE_FUNCTIONS) 

add_library(ida-libbfd-loader SHARED ${SOURCES})
target_link_libraries(ida-libbfd-loader ${IDA_LIBRARIES} ${LIBBFD_LIBRARIES})
set_target_properties(ida-libbfd-loader PROPERTIES OUTPUT_NAME "ida-libbfd-loader" PREFIX "" SUFFIX "${IDA_PLUGIN_EXT}")