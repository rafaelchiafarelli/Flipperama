#####################################
cmake_minimum_required (VERSION 2.8) 
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
project (raspicam_test)
find_package(raspicam REQUIRED)

add_executable (simpletest_raspicam simpletest_raspicam.cpp)  
target_link_libraries (simpletest_raspicam ${raspicam_LIBS})

add_executable (raw_ramdisk raw_file_ramdisk.cpp)  
target_link_libraries (raw_ramdisk ${raspicam_LIBS})

add_executable (continuous continuous_raw_file_ramdisk.cpp)  
target_link_libraries (continuous ${raspicam_LIBS})

find_package(Curses REQUIRED)
target_link_libraries(continuous ${CURSES_LIBRARY})
target_link_libraries (continuous ${raspicam_LIBS})


find_package(OpenCV)
IF  ( OpenCV_FOUND AND raspicam_CV_FOUND)
MESSAGE(STATUS ${OpenCV_LIBS})
MESSAGE(STATUS ${OpenCV_INCLUDE_DIRS})
MESSAGE(STATUS ${raspicam_LIBS})
MESSAGE(STATUS "COMPILING OPENCV TESTS")
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable (simple_cv simple_test_cv.cpp)  
target_link_libraries (simple_cv ${raspicam_CV_LIBS})


add_executable(EventROI EventROI.cpp)

add_library(Measure Measure.cpp)

target_link_libraries(EventROI
        PRIVATE
        inotify-cpp::inotify-cpp
        Boost::unit_test_framework
        Boost::system
        Boost::filesystem
        ${CMAKE_THREAD_LIBS_INIT}
        Measure
        mosquitto
        ${OpenCV_LIBS}
        ${raspicam_LIBS}
        )

ELSE()
MESSAGE(FATAL_ERROR "OPENCV NOT FOUND IN YOUR SYSTEM")
ENDIF()

#####################################

###############################################################################
# EventROI-CPP
###############################################################################

find_package(inotify-cpp CONFIG REQUIRED)

###############################################################################
# Boost
###############################################################################
find_package(
        Boost 1.67.0
        COMPONENTS unit_test_framework system filesystem
        REQUIRED
)

###############################################################################
# Thread
###############################################################################
find_package(Threads)

###############################################################################
# Target
###############################################################################

        
 
