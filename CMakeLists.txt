cmake_minimum_required(VERSION 3.0.0)
project(MIPT-CPU VERSION 0.1.0)

include(CTest)
enable_testing()

set(ASSEMBLY_FILES  ./Assembly/main.c
                    ./Assembly/assembly.c)
set(ASSEMBLY_INCLUDE ./Assembly/include/assembly.h)

add_executable(Assembly ${ASSEMBLY_FILES} ${ASSEMBLY_INCLUDE})
target_include_directories(Assembly PUBLIC ./Assembly/include)

add_subdirectory(Dependencies)
target_link_libraries(Assembly Dependencies)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
