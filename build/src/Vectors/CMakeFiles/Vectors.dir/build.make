# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = "/home/leo-gomez/Coding/Game Development/Bushido"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/leo-gomez/Coding/Game Development/Bushido/build"

# Include any dependencies generated for this target.
include src/Vectors/CMakeFiles/Vectors.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Vectors/CMakeFiles/Vectors.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Vectors/CMakeFiles/Vectors.dir/progress.make

# Include the compile flags for this target's objects.
include src/Vectors/CMakeFiles/Vectors.dir/flags.make

src/Vectors/CMakeFiles/Vectors.dir/vector2.c.o: src/Vectors/CMakeFiles/Vectors.dir/flags.make
src/Vectors/CMakeFiles/Vectors.dir/vector2.c.o: /home/leo-gomez/Coding/Game\ Development/Bushido/src/Vectors/vector2.c
src/Vectors/CMakeFiles/Vectors.dir/vector2.c.o: src/Vectors/CMakeFiles/Vectors.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/leo-gomez/Coding/Game Development/Bushido/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/Vectors/CMakeFiles/Vectors.dir/vector2.c.o"
	cd "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/Vectors/CMakeFiles/Vectors.dir/vector2.c.o -MF CMakeFiles/Vectors.dir/vector2.c.o.d -o CMakeFiles/Vectors.dir/vector2.c.o -c "/home/leo-gomez/Coding/Game Development/Bushido/src/Vectors/vector2.c"

src/Vectors/CMakeFiles/Vectors.dir/vector2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Vectors.dir/vector2.c.i"
	cd "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/leo-gomez/Coding/Game Development/Bushido/src/Vectors/vector2.c" > CMakeFiles/Vectors.dir/vector2.c.i

src/Vectors/CMakeFiles/Vectors.dir/vector2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Vectors.dir/vector2.c.s"
	cd "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/leo-gomez/Coding/Game Development/Bushido/src/Vectors/vector2.c" -o CMakeFiles/Vectors.dir/vector2.c.s

# Object files for target Vectors
Vectors_OBJECTS = \
"CMakeFiles/Vectors.dir/vector2.c.o"

# External object files for target Vectors
Vectors_EXTERNAL_OBJECTS =

src/Vectors/libVectors.a: src/Vectors/CMakeFiles/Vectors.dir/vector2.c.o
src/Vectors/libVectors.a: src/Vectors/CMakeFiles/Vectors.dir/build.make
src/Vectors/libVectors.a: src/Vectors/CMakeFiles/Vectors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/leo-gomez/Coding/Game Development/Bushido/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libVectors.a"
	cd "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors" && $(CMAKE_COMMAND) -P CMakeFiles/Vectors.dir/cmake_clean_target.cmake
	cd "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vectors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Vectors/CMakeFiles/Vectors.dir/build: src/Vectors/libVectors.a
.PHONY : src/Vectors/CMakeFiles/Vectors.dir/build

src/Vectors/CMakeFiles/Vectors.dir/clean:
	cd "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors" && $(CMAKE_COMMAND) -P CMakeFiles/Vectors.dir/cmake_clean.cmake
.PHONY : src/Vectors/CMakeFiles/Vectors.dir/clean

src/Vectors/CMakeFiles/Vectors.dir/depend:
	cd "/home/leo-gomez/Coding/Game Development/Bushido/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/leo-gomez/Coding/Game Development/Bushido" "/home/leo-gomez/Coding/Game Development/Bushido/src/Vectors" "/home/leo-gomez/Coding/Game Development/Bushido/build" "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors" "/home/leo-gomez/Coding/Game Development/Bushido/build/src/Vectors/CMakeFiles/Vectors.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/Vectors/CMakeFiles/Vectors.dir/depend

