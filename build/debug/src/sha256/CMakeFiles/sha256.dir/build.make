# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1210/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1210/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danila/std/pi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danila/std/pi/build/debug

# Include any dependencies generated for this target.
include src/sha256/CMakeFiles/sha256.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/sha256/CMakeFiles/sha256.dir/compiler_depend.make

# Include the progress variables for this target.
include src/sha256/CMakeFiles/sha256.dir/progress.make

# Include the compile flags for this target's objects.
include src/sha256/CMakeFiles/sha256.dir/flags.make

src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.o: src/sha256/CMakeFiles/sha256.dir/flags.make
src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.o: /home/danila/std/pi/src/sha256/sha256/sha256.cpp
src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.o: src/sha256/CMakeFiles/sha256.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.o"
	cd /home/danila/std/pi/build/debug/src/sha256 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.o -MF CMakeFiles/sha256.dir/sha256/sha256.cpp.o.d -o CMakeFiles/sha256.dir/sha256/sha256.cpp.o -c /home/danila/std/pi/src/sha256/sha256/sha256.cpp

src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sha256.dir/sha256/sha256.cpp.i"
	cd /home/danila/std/pi/build/debug/src/sha256 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/std/pi/src/sha256/sha256/sha256.cpp > CMakeFiles/sha256.dir/sha256/sha256.cpp.i

src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sha256.dir/sha256/sha256.cpp.s"
	cd /home/danila/std/pi/build/debug/src/sha256 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/std/pi/src/sha256/sha256/sha256.cpp -o CMakeFiles/sha256.dir/sha256/sha256.cpp.s

# Object files for target sha256
sha256_OBJECTS = \
"CMakeFiles/sha256.dir/sha256/sha256.cpp.o"

# External object files for target sha256
sha256_EXTERNAL_OBJECTS =

src/sha256/libsha256.a: src/sha256/CMakeFiles/sha256.dir/sha256/sha256.cpp.o
src/sha256/libsha256.a: src/sha256/CMakeFiles/sha256.dir/build.make
src/sha256/libsha256.a: src/sha256/CMakeFiles/sha256.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsha256.a"
	cd /home/danila/std/pi/build/debug/src/sha256 && $(CMAKE_COMMAND) -P CMakeFiles/sha256.dir/cmake_clean_target.cmake
	cd /home/danila/std/pi/build/debug/src/sha256 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sha256.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/sha256/CMakeFiles/sha256.dir/build: src/sha256/libsha256.a
.PHONY : src/sha256/CMakeFiles/sha256.dir/build

src/sha256/CMakeFiles/sha256.dir/clean:
	cd /home/danila/std/pi/build/debug/src/sha256 && $(CMAKE_COMMAND) -P CMakeFiles/sha256.dir/cmake_clean.cmake
.PHONY : src/sha256/CMakeFiles/sha256.dir/clean

src/sha256/CMakeFiles/sha256.dir/depend:
	cd /home/danila/std/pi/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danila/std/pi /home/danila/std/pi/src/sha256 /home/danila/std/pi/build/debug /home/danila/std/pi/build/debug/src/sha256 /home/danila/std/pi/build/debug/src/sha256/CMakeFiles/sha256.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sha256/CMakeFiles/sha256.dir/depend

