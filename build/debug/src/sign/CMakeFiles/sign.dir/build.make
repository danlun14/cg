# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /snap/cmake/1186/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1186/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danila/std/pi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danila/std/pi/build/debug

# Include any dependencies generated for this target.
include src/sign/CMakeFiles/sign.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/sign/CMakeFiles/sign.dir/compiler_depend.make

# Include the progress variables for this target.
include src/sign/CMakeFiles/sign.dir/progress.make

# Include the compile flags for this target's objects.
include src/sign/CMakeFiles/sign.dir/flags.make

src/sign/CMakeFiles/sign.dir/sign/sign.cpp.o: src/sign/CMakeFiles/sign.dir/flags.make
src/sign/CMakeFiles/sign.dir/sign/sign.cpp.o: /home/danila/std/pi/src/sign/sign/sign.cpp
src/sign/CMakeFiles/sign.dir/sign/sign.cpp.o: src/sign/CMakeFiles/sign.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/sign/CMakeFiles/sign.dir/sign/sign.cpp.o"
	cd /home/danila/std/pi/build/debug/src/sign && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/sign/CMakeFiles/sign.dir/sign/sign.cpp.o -MF CMakeFiles/sign.dir/sign/sign.cpp.o.d -o CMakeFiles/sign.dir/sign/sign.cpp.o -c /home/danila/std/pi/src/sign/sign/sign.cpp

src/sign/CMakeFiles/sign.dir/sign/sign.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sign.dir/sign/sign.cpp.i"
	cd /home/danila/std/pi/build/debug/src/sign && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/std/pi/src/sign/sign/sign.cpp > CMakeFiles/sign.dir/sign/sign.cpp.i

src/sign/CMakeFiles/sign.dir/sign/sign.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sign.dir/sign/sign.cpp.s"
	cd /home/danila/std/pi/build/debug/src/sign && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/std/pi/src/sign/sign/sign.cpp -o CMakeFiles/sign.dir/sign/sign.cpp.s

# Object files for target sign
sign_OBJECTS = \
"CMakeFiles/sign.dir/sign/sign.cpp.o"

# External object files for target sign
sign_EXTERNAL_OBJECTS =

src/sign/libsign.a: src/sign/CMakeFiles/sign.dir/sign/sign.cpp.o
src/sign/libsign.a: src/sign/CMakeFiles/sign.dir/build.make
src/sign/libsign.a: src/sign/CMakeFiles/sign.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsign.a"
	cd /home/danila/std/pi/build/debug/src/sign && $(CMAKE_COMMAND) -P CMakeFiles/sign.dir/cmake_clean_target.cmake
	cd /home/danila/std/pi/build/debug/src/sign && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sign.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/sign/CMakeFiles/sign.dir/build: src/sign/libsign.a
.PHONY : src/sign/CMakeFiles/sign.dir/build

src/sign/CMakeFiles/sign.dir/clean:
	cd /home/danila/std/pi/build/debug/src/sign && $(CMAKE_COMMAND) -P CMakeFiles/sign.dir/cmake_clean.cmake
.PHONY : src/sign/CMakeFiles/sign.dir/clean

src/sign/CMakeFiles/sign.dir/depend:
	cd /home/danila/std/pi/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danila/std/pi /home/danila/std/pi/src/sign /home/danila/std/pi/build/debug /home/danila/std/pi/build/debug/src/sign /home/danila/std/pi/build/debug/src/sign/CMakeFiles/sign.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sign/CMakeFiles/sign.dir/depend
