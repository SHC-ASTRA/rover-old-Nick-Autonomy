# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/rover-Autonomy/navigatorApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/rover-Autonomy/build

# Include any dependencies generated for this target.
include CMakeFiles/navigator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/navigator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/navigator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/navigator.dir/flags.make

CMakeFiles/navigator.dir/src/navigator.cpp.o: CMakeFiles/navigator.dir/flags.make
CMakeFiles/navigator.dir/src/navigator.cpp.o: /home/nick/rover-Autonomy/navigatorApp/src/navigator.cpp
CMakeFiles/navigator.dir/src/navigator.cpp.o: CMakeFiles/navigator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/rover-Autonomy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/navigator.dir/src/navigator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/navigator.dir/src/navigator.cpp.o -MF CMakeFiles/navigator.dir/src/navigator.cpp.o.d -o CMakeFiles/navigator.dir/src/navigator.cpp.o -c /home/nick/rover-Autonomy/navigatorApp/src/navigator.cpp

CMakeFiles/navigator.dir/src/navigator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/navigator.dir/src/navigator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/rover-Autonomy/navigatorApp/src/navigator.cpp > CMakeFiles/navigator.dir/src/navigator.cpp.i

CMakeFiles/navigator.dir/src/navigator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/navigator.dir/src/navigator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/rover-Autonomy/navigatorApp/src/navigator.cpp -o CMakeFiles/navigator.dir/src/navigator.cpp.s

# Object files for target navigator
navigator_OBJECTS = \
"CMakeFiles/navigator.dir/src/navigator.cpp.o"

# External object files for target navigator
navigator_EXTERNAL_OBJECTS =

navigator: CMakeFiles/navigator.dir/src/navigator.cpp.o
navigator: CMakeFiles/navigator.dir/build.make
navigator: libnav.a
navigator: CMakeFiles/navigator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/rover-Autonomy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable navigator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/navigator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/navigator.dir/build: navigator
.PHONY : CMakeFiles/navigator.dir/build

CMakeFiles/navigator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/navigator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/navigator.dir/clean

CMakeFiles/navigator.dir/depend:
	cd /home/nick/rover-Autonomy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/rover-Autonomy/navigatorApp /home/nick/rover-Autonomy/navigatorApp /home/nick/rover-Autonomy/build /home/nick/rover-Autonomy/build /home/nick/rover-Autonomy/build/CMakeFiles/navigator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/navigator.dir/depend

