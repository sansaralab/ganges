cmake_minimum_required(VERSION 3.5)
project(ganges)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/FindEvent.cmake")

include(CheckCCompilerFlag)
check_c_compiler_flag("-std=c11" COMPILER_SUPPORTS_C11)
check_c_compiler_flag("-std=c1x" COMPILER_SUPPORTS_C1X)
if(COMPILER_SUPPORTS_C11)
    set(CMAKE_C_FLAGS "-std=c11 ${CMAKE_C_FLAGS}")
elseif(COMPILER_SUPPORTS_C1X)
    set(CMAKE_C_FLAGS "-std=c1x ${CMAKE_C_FLAGS}")
else()
    message(STATUS "The compiler ${CMAKE_C_COMPILER} has no C11/C1x support, which is required.")
endif()


add_subdirectory(cmake)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(SOURCE_FILES src/main.c src/queue/queue.c src/queue/queue.h src/server/async.c src/server/async.h)
add_executable(ganges ${SOURCE_FILES})

find_package(LibEvent)
if(${LibEvent_FOUND})
    target_link_libraries(ganges ${LIBEVENT_LIB})
else()
    message(WARNING "LibEvent NOT FOUND")
    set(MISSING_LIB 1)
endif()
