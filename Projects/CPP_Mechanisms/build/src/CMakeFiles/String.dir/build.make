# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build

# Include any dependencies generated for this target.
include src/CMakeFiles/String.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/String.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/String.dir/flags.make

src/CMakeFiles/String.dir/String.cpp.o: src/CMakeFiles/String.dir/flags.make
src/CMakeFiles/String.dir/String.cpp.o: ../src/String.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/String.dir/String.cpp.o"
	cd /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/String.dir/String.cpp.o -c /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/src/String.cpp

src/CMakeFiles/String.dir/String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/String.dir/String.cpp.i"
	cd /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/src/String.cpp > CMakeFiles/String.dir/String.cpp.i

src/CMakeFiles/String.dir/String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/String.dir/String.cpp.s"
	cd /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/src/String.cpp -o CMakeFiles/String.dir/String.cpp.s

# Object files for target String
String_OBJECTS = \
"CMakeFiles/String.dir/String.cpp.o"

# External object files for target String
String_EXTERNAL_OBJECTS =

src/libString.a: src/CMakeFiles/String.dir/String.cpp.o
src/libString.a: src/CMakeFiles/String.dir/build.make
src/libString.a: src/CMakeFiles/String.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libString.a"
	cd /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src && $(CMAKE_COMMAND) -P CMakeFiles/String.dir/cmake_clean_target.cmake
	cd /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/String.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/String.dir/build: src/libString.a

.PHONY : src/CMakeFiles/String.dir/build

src/CMakeFiles/String.dir/clean:
	cd /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src && $(CMAKE_COMMAND) -P CMakeFiles/String.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/String.dir/clean

src/CMakeFiles/String.dir/depend:
	cd /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/src /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src /home/jakub/Dev/Projects-CPP/Projects/CPP_Mechanisms/build/src/CMakeFiles/String.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/String.dir/depend
