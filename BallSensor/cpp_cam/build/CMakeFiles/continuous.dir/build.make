# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/cpp_cam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/cpp_cam/build

# Include any dependencies generated for this target.
include CMakeFiles/continuous.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/continuous.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/continuous.dir/flags.make

CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.o: CMakeFiles/continuous.dir/flags.make
CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.o: ../continuous_raw_file_ramdisk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/cpp_cam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.o -c /home/pi/cpp_cam/continuous_raw_file_ramdisk.cpp

CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/cpp_cam/continuous_raw_file_ramdisk.cpp > CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.i

CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/cpp_cam/continuous_raw_file_ramdisk.cpp -o CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.s

# Object files for target continuous
continuous_OBJECTS = \
"CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.o"

# External object files for target continuous
continuous_EXTERNAL_OBJECTS =

continuous: CMakeFiles/continuous.dir/continuous_raw_file_ramdisk.cpp.o
continuous: CMakeFiles/continuous.dir/build.make
continuous: /usr/lib/arm-linux-gnueabihf/libcurses.so
continuous: /usr/lib/arm-linux-gnueabihf/libcurses.so
continuous: CMakeFiles/continuous.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/cpp_cam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable continuous"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/continuous.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/continuous.dir/build: continuous

.PHONY : CMakeFiles/continuous.dir/build

CMakeFiles/continuous.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/continuous.dir/cmake_clean.cmake
.PHONY : CMakeFiles/continuous.dir/clean

CMakeFiles/continuous.dir/depend:
	cd /home/pi/cpp_cam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/cpp_cam /home/pi/cpp_cam /home/pi/cpp_cam/build /home/pi/cpp_cam/build /home/pi/cpp_cam/build/CMakeFiles/continuous.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/continuous.dir/depend

