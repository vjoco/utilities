# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /data

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/build

# Include any dependencies generated for this target.
include CMakeFiles/cc1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cc1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cc1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cc1.dir/flags.make

CMakeFiles/cc1.dir/Hal.cpp.o: CMakeFiles/cc1.dir/flags.make
CMakeFiles/cc1.dir/Hal.cpp.o: /data/Hal.cpp
CMakeFiles/cc1.dir/Hal.cpp.o: CMakeFiles/cc1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cc1.dir/Hal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cc1.dir/Hal.cpp.o -MF CMakeFiles/cc1.dir/Hal.cpp.o.d -o CMakeFiles/cc1.dir/Hal.cpp.o -c /data/Hal.cpp

CMakeFiles/cc1.dir/Hal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cc1.dir/Hal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/Hal.cpp > CMakeFiles/cc1.dir/Hal.cpp.i

CMakeFiles/cc1.dir/Hal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cc1.dir/Hal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/Hal.cpp -o CMakeFiles/cc1.dir/Hal.cpp.s

CMakeFiles/cc1.dir/cc1101_lucky.cpp.o: CMakeFiles/cc1.dir/flags.make
CMakeFiles/cc1.dir/cc1101_lucky.cpp.o: /data/cc1101_lucky.cpp
CMakeFiles/cc1.dir/cc1101_lucky.cpp.o: CMakeFiles/cc1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cc1.dir/cc1101_lucky.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cc1.dir/cc1101_lucky.cpp.o -MF CMakeFiles/cc1.dir/cc1101_lucky.cpp.o.d -o CMakeFiles/cc1.dir/cc1101_lucky.cpp.o -c /data/cc1101_lucky.cpp

CMakeFiles/cc1.dir/cc1101_lucky.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cc1.dir/cc1101_lucky.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/cc1101_lucky.cpp > CMakeFiles/cc1.dir/cc1101_lucky.cpp.i

CMakeFiles/cc1.dir/cc1101_lucky.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cc1.dir/cc1101_lucky.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/cc1101_lucky.cpp -o CMakeFiles/cc1.dir/cc1101_lucky.cpp.s

CMakeFiles/cc1.dir/Module.cpp.o: CMakeFiles/cc1.dir/flags.make
CMakeFiles/cc1.dir/Module.cpp.o: /data/Module.cpp
CMakeFiles/cc1.dir/Module.cpp.o: CMakeFiles/cc1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cc1.dir/Module.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cc1.dir/Module.cpp.o -MF CMakeFiles/cc1.dir/Module.cpp.o.d -o CMakeFiles/cc1.dir/Module.cpp.o -c /data/Module.cpp

CMakeFiles/cc1.dir/Module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cc1.dir/Module.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/Module.cpp > CMakeFiles/cc1.dir/Module.cpp.i

CMakeFiles/cc1.dir/Module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cc1.dir/Module.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/Module.cpp -o CMakeFiles/cc1.dir/Module.cpp.s

CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o: CMakeFiles/cc1.dir/flags.make
CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o: /data/CC1101/CC1101.cpp
CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o: CMakeFiles/cc1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o -MF CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o.d -o CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o -c /data/CC1101/CC1101.cpp

CMakeFiles/cc1.dir/CC1101/CC1101.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cc1.dir/CC1101/CC1101.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/CC1101/CC1101.cpp > CMakeFiles/cc1.dir/CC1101/CC1101.cpp.i

CMakeFiles/cc1.dir/CC1101/CC1101.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cc1.dir/CC1101/CC1101.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/CC1101/CC1101.cpp -o CMakeFiles/cc1.dir/CC1101/CC1101.cpp.s

CMakeFiles/cc1.dir/PhysicalLayer.cpp.o: CMakeFiles/cc1.dir/flags.make
CMakeFiles/cc1.dir/PhysicalLayer.cpp.o: /data/PhysicalLayer.cpp
CMakeFiles/cc1.dir/PhysicalLayer.cpp.o: CMakeFiles/cc1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cc1.dir/PhysicalLayer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cc1.dir/PhysicalLayer.cpp.o -MF CMakeFiles/cc1.dir/PhysicalLayer.cpp.o.d -o CMakeFiles/cc1.dir/PhysicalLayer.cpp.o -c /data/PhysicalLayer.cpp

CMakeFiles/cc1.dir/PhysicalLayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cc1.dir/PhysicalLayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/PhysicalLayer.cpp > CMakeFiles/cc1.dir/PhysicalLayer.cpp.i

CMakeFiles/cc1.dir/PhysicalLayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cc1.dir/PhysicalLayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/PhysicalLayer.cpp -o CMakeFiles/cc1.dir/PhysicalLayer.cpp.s

# Object files for target cc1
cc1_OBJECTS = \
"CMakeFiles/cc1.dir/Hal.cpp.o" \
"CMakeFiles/cc1.dir/cc1101_lucky.cpp.o" \
"CMakeFiles/cc1.dir/Module.cpp.o" \
"CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o" \
"CMakeFiles/cc1.dir/PhysicalLayer.cpp.o"

# External object files for target cc1
cc1_EXTERNAL_OBJECTS =

cc1: CMakeFiles/cc1.dir/Hal.cpp.o
cc1: CMakeFiles/cc1.dir/cc1101_lucky.cpp.o
cc1: CMakeFiles/cc1.dir/Module.cpp.o
cc1: CMakeFiles/cc1.dir/CC1101/CC1101.cpp.o
cc1: CMakeFiles/cc1.dir/PhysicalLayer.cpp.o
cc1: CMakeFiles/cc1.dir/build.make
cc1: CMakeFiles/cc1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable cc1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cc1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cc1.dir/build: cc1
.PHONY : CMakeFiles/cc1.dir/build

CMakeFiles/cc1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cc1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cc1.dir/clean

CMakeFiles/cc1.dir/depend:
	cd /data/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data /data /data/build /data/build /data/build/CMakeFiles/cc1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cc1.dir/depend

