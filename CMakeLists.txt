#        _
#  _ __ | |__   ___ __ _ __   _____   ___   _ _ __ ___
# | '_ \| '_ \ |__ `_ \ '_ \ / _ \ \ / / | | | '_ ` _ \
# | |_) | | | |/ _  __/ | | | (_) \ V /| |_| | | | | | |
# | .__/|_| |_|\__,___|_| |_|\___/ \_/  \__,_|_| |_| |_|
# |_|
#
cmake_policy(SET CMP0048 NEW)
project(ev3dev-c VERSION 0.1.0)
cmake_minimum_required(VERSION 3.10)
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Find required packages
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#find_package(package ${PACKAGE_VERSION} CONFIG REQUIRED)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Targets
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
add_library(${PROJECT_NAME}
    source/ev3/ev3_light.c
    source/ev3/ev3_link/ev3_link.c
    source/ev3/ev3.c
    source/ev3/ev3_dc.c
    source/ev3/ev3_tacho.c
    source/ev3/ev3_sensor.c
    source/ev3/ev3_port.c
    source/ev3/crc32.c
    source/ev3/ev3_servo.c
    source/ev3/brick.c
    source/ev3/ev3_led.c
    3d_party/modp_numtoa.c
)

#target_link_libraries(${PROJECT_NAME}
#    lib
#)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/source/ev3>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/3d_party>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    #PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

#set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER
    #${CMAKE_CURRENT_SOURCE_DIR}/source/ev3/ev3.h)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Install/export targets and files
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
set(CONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
set(PROJECT_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake")
set(PROJECT_CONFIG_FILE "${PROJECT_NAME}-config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")

# generate package version file
write_basic_package_version_file(
    ${PROJECT_VERSION_FILE}
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# install targets
install(TARGETS ${PROJECT_NAME}
        EXPORT ${TARGETS_EXPORT_NAME}
        LIBRARY
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES
        PUBLIC_HEADER
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ev3/ev3.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ev3/ev3_both.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ev3/ev3_light.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/ev3/ev3_sensor.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT devel
)

# install version file
install(FILES ${PROJECT_VERSION_FILE}
        DESTINATION ${CONFIG_INSTALL_DIR}
)

set(AE_NAMESPACE "ae::")

# build directory package config
export(EXPORT ${TARGETS_EXPORT_NAME}
       FILE ${PROJECT_CONFIG_FILE}
       NAMESPACE ${AE_NAMESPACE}
)

# installed package config
install(EXPORT ${TARGETS_EXPORT_NAME}
        DESTINATION ${CONFIG_INSTALL_DIR}
        FILE ${PROJECT_CONFIG_FILE}
        NAMESPACE ${AE_NAMESPACE}
)

# add to CMake registry
export(PACKAGE ${PROJECT_NAME})
