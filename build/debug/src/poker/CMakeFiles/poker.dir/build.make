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
include src/poker/CMakeFiles/poker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/poker/CMakeFiles/poker.dir/compiler_depend.make

# Include the progress variables for this target.
include src/poker/CMakeFiles/poker.dir/progress.make

# Include the compile flags for this target's objects.
include src/poker/CMakeFiles/poker.dir/flags.make

src/poker/CMakeFiles/poker.dir/poker/poker.cpp.o: src/poker/CMakeFiles/poker.dir/flags.make
src/poker/CMakeFiles/poker.dir/poker/poker.cpp.o: /home/danila/std/pi/src/poker/poker/poker.cpp
src/poker/CMakeFiles/poker.dir/poker/poker.cpp.o: src/poker/CMakeFiles/poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/poker/CMakeFiles/poker.dir/poker/poker.cpp.o"
	cd /home/danila/std/pi/build/debug/src/poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/poker/CMakeFiles/poker.dir/poker/poker.cpp.o -MF CMakeFiles/poker.dir/poker/poker.cpp.o.d -o CMakeFiles/poker.dir/poker/poker.cpp.o -c /home/danila/std/pi/src/poker/poker/poker.cpp

src/poker/CMakeFiles/poker.dir/poker/poker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/poker.dir/poker/poker.cpp.i"
	cd /home/danila/std/pi/build/debug/src/poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/std/pi/src/poker/poker/poker.cpp > CMakeFiles/poker.dir/poker/poker.cpp.i

src/poker/CMakeFiles/poker.dir/poker/poker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/poker.dir/poker/poker.cpp.s"
	cd /home/danila/std/pi/build/debug/src/poker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/std/pi/src/poker/poker/poker.cpp -o CMakeFiles/poker.dir/poker/poker.cpp.s

# Object files for target poker
poker_OBJECTS = \
"CMakeFiles/poker.dir/poker/poker.cpp.o"

# External object files for target poker
poker_EXTERNAL_OBJECTS =

/home/danila/std/pi/bin/poker: src/poker/CMakeFiles/poker.dir/poker/poker.cpp.o
/home/danila/std/pi/bin/poker: src/poker/CMakeFiles/poker.dir/build.make
/home/danila/std/pi/bin/poker: src/basic/libbasic.a
/home/danila/std/pi/bin/poker: src/cipher/libcipher.a
/home/danila/std/pi/bin/poker: src/basic/libbasic.a
/home/danila/std/pi/bin/poker: src/BigInt/libBigInt.a
/home/danila/std/pi/bin/poker: src/poker/CMakeFiles/poker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/danila/std/pi/bin/poker"
	cd /home/danila/std/pi/build/debug/src/poker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/poker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/poker/CMakeFiles/poker.dir/build: /home/danila/std/pi/bin/poker
.PHONY : src/poker/CMakeFiles/poker.dir/build

src/poker/CMakeFiles/poker.dir/clean:
	cd /home/danila/std/pi/build/debug/src/poker && $(CMAKE_COMMAND) -P CMakeFiles/poker.dir/cmake_clean.cmake
.PHONY : src/poker/CMakeFiles/poker.dir/clean

src/poker/CMakeFiles/poker.dir/depend:
	cd /home/danila/std/pi/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danila/std/pi /home/danila/std/pi/src/poker /home/danila/std/pi/build/debug /home/danila/std/pi/build/debug/src/poker /home/danila/std/pi/build/debug/src/poker/CMakeFiles/poker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/poker/CMakeFiles/poker.dir/depend

