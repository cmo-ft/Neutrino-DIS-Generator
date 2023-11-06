cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(pythia_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
#----------------------------------------------------------------------------
# Find pythia (required package)
#
find_package(Pythia8 REQUIRED COMPONENTS)
IF (PYTHIA8_FOUND)
    MESSAGE(STATUS "PYTHIA8 found at ${PYTHIA8_INCLUDE_DIR}")
    INCLUDE_DIRECTORIES(${PYTHIA8_INCLUDE_DIR})
    LINK_LIBRARIES(${PYTHIA8_LIBRARY})
ENDIF ()



add_executable(neutrino neutrino.cc)

INSTALL(TARGETS neutrino
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)