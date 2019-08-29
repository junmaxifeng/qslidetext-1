################################################################################
# Copyright (c) 2018, Induspotis, Inc.
# All rights reserved.
#
# Root cmake script entry
#
# author   : hunt978(hubq@initialsoft.com)
# create   : 2018-05-02 09:34:07 UTC
# modified : 2019-08-16 06:21:50 UTC
################################################################################

# cmake version
cmake_minimum_required(VERSION 3.5.0)

# project
project(qslidetext_plugin)

# collect sources
file(GLOB ROOT_SOURCES *.cc *.h)
set(SOURCES ${ROOT_SOURCES})
#group_by_folder(SOURCES ${CMAKE_CURRENT_LIST_DIR}/..)

# find dependencies
find_package(Qt5 COMPONENTS Core Widgets Designer REQUIRED)

# target
add_library(${PROJECT_NAME} SHARED ${SOURCES})
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS XT_BUILD_STATIC)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Designer)
target_link_libraries(${PROJECT_NAME} qslidetext_static)

# install to the qt installation
install(TARGETS qslidetext_plugin RUNTIME CONFIGURATIONS Release DESTINATION ${Qt5PluginsDesignerDir})
install(TARGETS qslidetext_plugin RUNTIME CONFIGURATIONS Release DESTINATION share/plugin )