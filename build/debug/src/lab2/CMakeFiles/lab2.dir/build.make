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
include src/lab2/CMakeFiles/lab2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/lab2/CMakeFiles/lab2.dir/compiler_depend.make

# Include the progress variables for this target.
include src/lab2/CMakeFiles/lab2.dir/progress.make

# Include the compile flags for this target's objects.
include src/lab2/CMakeFiles/lab2.dir/flags.make

src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.o: src/lab2/CMakeFiles/lab2.dir/flags.make
src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.o: /home/danila/std/pi/src/lab2/lab2/lab2.cpp
src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.o: src/lab2/CMakeFiles/lab2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.o"
	cd /home/danila/std/pi/build/debug/src/lab2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.o -MF CMakeFiles/lab2.dir/lab2/lab2.cpp.o.d -o CMakeFiles/lab2.dir/lab2/lab2.cpp.o -c /home/danila/std/pi/src/lab2/lab2/lab2.cpp

src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2.dir/lab2/lab2.cpp.i"
	cd /home/danila/std/pi/build/debug/src/lab2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/std/pi/src/lab2/lab2/lab2.cpp > CMakeFiles/lab2.dir/lab2/lab2.cpp.i

src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2.dir/lab2/lab2.cpp.s"
	cd /home/danila/std/pi/build/debug/src/lab2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/std/pi/src/lab2/lab2/lab2.cpp -o CMakeFiles/lab2.dir/lab2/lab2.cpp.s

# Object files for target lab2
lab2_OBJECTS = \
"CMakeFiles/lab2.dir/lab2/lab2.cpp.o"

# External object files for target lab2
lab2_EXTERNAL_OBJECTS =

/home/danila/std/pi/bin/lab2: src/lab2/CMakeFiles/lab2.dir/lab2/lab2.cpp.o
/home/danila/std/pi/bin/lab2: src/lab2/CMakeFiles/lab2.dir/build.make
/home/danila/std/pi/bin/lab2: src/cipher/libcipher.a
/home/danila/std/pi/bin/lab2: src/basic/libbasic.a
/home/danila/std/pi/bin/lab2: src/BigInt/libBigInt.a
/home/danila/std/pi/bin/lab2: src/lab2/CMakeFiles/lab2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/danila/std/pi/bin/lab2"
	cd /home/danila/std/pi/build/debug/src/lab2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lab2/CMakeFiles/lab2.dir/build: /home/danila/std/pi/bin/lab2
.PHONY : src/lab2/CMakeFiles/lab2.dir/build

src/lab2/CMakeFiles/lab2.dir/clean:
	cd /home/danila/std/pi/build/debug/src/lab2 && $(CMAKE_COMMAND) -P CMakeFiles/lab2.dir/cmake_clean.cmake
.PHONY : src/lab2/CMakeFiles/lab2.dir/clean

src/lab2/CMakeFiles/lab2.dir/depend:
	cd /home/danila/std/pi/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danila/std/pi /home/danila/std/pi/src/lab2 /home/danila/std/pi/build/debug /home/danila/std/pi/build/debug/src/lab2 /home/danila/std/pi/build/debug/src/lab2/CMakeFiles/lab2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/lab2/CMakeFiles/lab2.dir/depend

