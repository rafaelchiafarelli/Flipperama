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
include CMakeFiles/MQTTIntegration.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MQTTIntegration.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MQTTIntegration.dir/flags.make

CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.o: CMakeFiles/MQTTIntegration.dir/flags.make
CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.o: ../MQTTIntegration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/cpp_cam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.o -c /home/pi/cpp_cam/MQTTIntegration.cpp

CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/cpp_cam/MQTTIntegration.cpp > CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.i

CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/cpp_cam/MQTTIntegration.cpp -o CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.s

# Object files for target MQTTIntegration
MQTTIntegration_OBJECTS = \
"CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.o"

# External object files for target MQTTIntegration
MQTTIntegration_EXTERNAL_OBJECTS =

libMQTTIntegration.a: CMakeFiles/MQTTIntegration.dir/MQTTIntegration.cpp.o
libMQTTIntegration.a: CMakeFiles/MQTTIntegration.dir/build.make
libMQTTIntegration.a: CMakeFiles/MQTTIntegration.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/cpp_cam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMQTTIntegration.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MQTTIntegration.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MQTTIntegration.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MQTTIntegration.dir/build: libMQTTIntegration.a

.PHONY : CMakeFiles/MQTTIntegration.dir/build

CMakeFiles/MQTTIntegration.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MQTTIntegration.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MQTTIntegration.dir/clean

CMakeFiles/MQTTIntegration.dir/depend:
	cd /home/pi/cpp_cam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/cpp_cam /home/pi/cpp_cam /home/pi/cpp_cam/build /home/pi/cpp_cam/build /home/pi/cpp_cam/build/CMakeFiles/MQTTIntegration.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MQTTIntegration.dir/depend

