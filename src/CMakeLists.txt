################################################################################
# Copyright (c) 2018, Induspotis, Inc.
# All rights reserved.
#
# Root cmake script entry
#
# author   : hunt978(hubq@initialsoft.com)
# create   : 2018-05-02 09:34:07 UTC
# modified : 2019-08-16 06:21:12 UTC
################################################################################

# cmake version
cmake_minimum_required(VERSION 3.5.0)

# project
project(qslidetext)

# collect sources
file(GLOB_RECURSE SOURCES *.cc *.h *.qrc *.ui *.rc)
list(FILTER SOURCES EXCLUDE REGEX "plugins/")
#group_by_folder(SOURCES ${CMAKE_CURRENT_LIST_DIR}/..)

# qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# build target static
add_library(${PROJECT_NAME}_static STATIC ${SOURCES})
set_property(TARGET ${PROJECT_NAME}_static APPEND PROPERTY COMPILE_DEFINITIONS XT_BUILD_STATIC)
set_property(TARGET ${PROJECT_NAME}_static APPEND PROPERTY COMPILE_DEFINITIONS _CRT_SECURE_NO_WARNINGS)
target_include_directories(${PROJECT_NAME}_static PRIVATE ${Qt5GuiPrivateDir})
target_include_directories(${PROJECT_NAME}_static PRIVATE ${Qt5CorePrivateDir})
target_include_directories(${PROJECT_NAME}_static PUBLIC ${CMAKE_BINARY_DIR})
target_include_directories(${PROJECT_NAME}_static PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${PROJECT_NAME}_static Qt5::Core Qt5::Widgets)

# build target shared
add_library(${PROJECT_NAME} SHARED ${SOURCES})
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS BUILD_QSLIDETEXT)
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS _CRT_SECURE_NO_WARNINGS)
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt5GuiPrivateDir})
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt5CorePrivateDir})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)

# nav to plugins
add_subdirectory(plugins)

# install target
install(TARGETS qslidetext
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)
install(TARGETS qslidetext_static
  ARCHIVE DESTINATION lib
)
install(DIRECTORY ./ DESTINATION include FILES_MATCHING
  PATTERN "*.h"
  REGEX   "impl"                          EXCLUDE
  REGEX   "_p"                            EXCLUDE
  REGEX   "_internal"                     EXCLUDE
  REGEX   "plugins"                       EXCLUDE
  REGEX   "assets"                        EXCLUDE
)
install(DIRECTORY ../cmake/share/ DESTINATION share/cmake/qslidetext FILES_MATCHING
  PATTERN "*.cmake"
)