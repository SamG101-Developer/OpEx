cmake_minimum_required(VERSION 4.4.0)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
project(OpEx VERSION 0.1.0 LANGUAGES CXX)

# Set standard and include some common packages.
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_MODULE_STD ON)

# Collect source files.
file(GLOB_RECURSE MODULE_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE PUBLIC_HEADERS CONFIGURE_DEPENDS include/*.hpp)
add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
        FILE_SET CXX_MODULES BASE_DIRS src include FILES ${MODULE_SOURCES}
        FILE_SET HEADERS BASE_DIRS include FILES ${PUBLIC_HEADERS})

target_compile_options(
        ${PROJECT_NAME} PRIVATE -fmodules-ts)

target_compile_features(
        ${PROJECT_NAME} PUBLIC cxx_std_26)


# Create the OpEx library, and link 3rd party libraries.
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Install the library + export information
install(
        TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        FILE_SET CXX_MODULES DESTINATION lib/cmake/${PROJECT_NAME}/modules
        FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
        EXPORT ${PROJECT_NAME}Targets
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION lib/cmake/${PROJECT_NAME})

include(
        CMakePackageConfigHelpers)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION lib/cmake/${PROJECT_NAME})

install(
        FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION lib/cmake/${PROJECT_NAME})
