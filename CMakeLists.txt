cmake_minimum_required(VERSION 3.31)
project(OpEx)

set(PROJECT_VERSION 0.1.0)

# Set standard and include some common packages.
set(CMAKE_CXX_STANDARD 26)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Include 3rd party libraries and get headers.
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/**/*.hpp")

# Create the OpEx library, and link 3rd party libraries.
add_library(OpExLib INTERFACE)
target_include_directories(OpExLib INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Library installation configuration.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS OpExLib EXPORT OpExTargets)
install(EXPORT OpExTargets FILE OpExTargets.cmake NAMESPACE OpEx:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/OpEx)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/OpExConfigVersion.cmake" VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/OpExConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/OpExConfig.cmake" INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/OpEx)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/OpExConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/OpExConfigVersion.cmake" DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/OpEx)

# Create the test executable.
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE OpExLib)
