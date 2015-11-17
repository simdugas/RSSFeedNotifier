cmake_minimum_required(VERSION 3.3)
project(RSSFeedNotifier)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

## Build the main program executable
set( SOURCE_FILES main.cpp )

## Build the RSSParser Sample Executable
add_executable( RSSParser RSSParser.cpp )

find_package( TinyXML2 )

include_directories( ${TINYXML2_INCLUDE_DIR} )
target_link_libraries( RSSParser ${TINYXML2_LIBRARIES} )
