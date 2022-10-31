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
CMAKE_COMMAND = /snap/cmake/1156/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1156/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danila/std/pi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danila/std/pi/build/debug

# Include any dependencies generated for this target.
include src/cipher/CMakeFiles/cipher.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/cipher/CMakeFiles/cipher.dir/compiler_depend.make

# Include the progress variables for this target.
include src/cipher/CMakeFiles/cipher.dir/progress.make

# Include the compile flags for this target's objects.
include src/cipher/CMakeFiles/cipher.dir/flags.make

src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.o: src/cipher/CMakeFiles/cipher.dir/flags.make
src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.o: /home/danila/std/pi/src/cipher/cipher/cipher.cpp
src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.o: src/cipher/CMakeFiles/cipher.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.o"
	cd /home/danila/std/pi/build/debug/src/cipher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.o -MF CMakeFiles/cipher.dir/cipher/cipher.cpp.o.d -o CMakeFiles/cipher.dir/cipher/cipher.cpp.o -c /home/danila/std/pi/src/cipher/cipher/cipher.cpp

src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cipher.dir/cipher/cipher.cpp.i"
	cd /home/danila/std/pi/build/debug/src/cipher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/std/pi/src/cipher/cipher/cipher.cpp > CMakeFiles/cipher.dir/cipher/cipher.cpp.i

src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cipher.dir/cipher/cipher.cpp.s"
	cd /home/danila/std/pi/build/debug/src/cipher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/std/pi/src/cipher/cipher/cipher.cpp -o CMakeFiles/cipher.dir/cipher/cipher.cpp.s

# Object files for target cipher
cipher_OBJECTS = \
"CMakeFiles/cipher.dir/cipher/cipher.cpp.o"

# External object files for target cipher
cipher_EXTERNAL_OBJECTS =

src/cipher/libcipher.a: src/cipher/CMakeFiles/cipher.dir/cipher/cipher.cpp.o
src/cipher/libcipher.a: src/cipher/CMakeFiles/cipher.dir/build.make
src/cipher/libcipher.a: src/cipher/CMakeFiles/cipher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danila/std/pi/build/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcipher.a"
	cd /home/danila/std/pi/build/debug/src/cipher && $(CMAKE_COMMAND) -P CMakeFiles/cipher.dir/cmake_clean_target.cmake
	cd /home/danila/std/pi/build/debug/src/cipher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cipher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/cipher/CMakeFiles/cipher.dir/build: src/cipher/libcipher.a
.PHONY : src/cipher/CMakeFiles/cipher.dir/build

src/cipher/CMakeFiles/cipher.dir/clean:
	cd /home/danila/std/pi/build/debug/src/cipher && $(CMAKE_COMMAND) -P CMakeFiles/cipher.dir/cmake_clean.cmake
.PHONY : src/cipher/CMakeFiles/cipher.dir/clean

src/cipher/CMakeFiles/cipher.dir/depend:
	cd /home/danila/std/pi/build/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danila/std/pi /home/danila/std/pi/src/cipher /home/danila/std/pi/build/debug /home/danila/std/pi/build/debug/src/cipher /home/danila/std/pi/build/debug/src/cipher/CMakeFiles/cipher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cipher/CMakeFiles/cipher.dir/depend

