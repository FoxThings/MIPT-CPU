cmake_minimum_required(VERSION 3.0.0)
project(Dependencies VERSION 0.1.0)

include(CTest)
enable_testing()

set(PUBLIC_INCLUDE  ./include/fileManager.h
                    ./include/errorCodes.h)
set(FILES fileManager.c)

add_library(Dependencies STATIC ${PUBLIC_INCLUDE} ${FILES})
target_include_directories(Dependencies PUBLIC ./include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
